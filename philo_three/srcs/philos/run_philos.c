/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:37:28 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/10 16:05:49 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		run_philo_process(t_philo *philo)
{
	philo->pid = fork();
	if (philo->pid == 0)
	{
		pthread_create(&philo->th, NULL, &routine, philo);
		pthread_detach(philo->th);
		while (g_data.running)
		{
			post_nb_meals_reached(philo);
			post_dead(philo);
			ms_sleep(1);
		}
		exit(0);
	}
}

void		run_philos(t_philo **philos)
{
	int			i;
	pthread_t	dead_monitor_th;
	pthread_t	nb_meals_monitor_th;

	i = 0;
	while (i < g_data.nb_philos)
	{
		run_philo_process(philos[i]);
		i++;
	}
	pthread_create(&dead_monitor_th, NULL, &monitor_dead, philos);
	pthread_create(&nb_meals_monitor_th, NULL, &monitor_nb_meals, philos);
	pthread_detach(dead_monitor_th);
	pthread_detach(nb_meals_monitor_th);
	while (g_data.running)
		ms_sleep(1);
	printf("yo run boucle\n");
	i = 0;
	while (i < g_data.nb_philos)
	{
		kill(philos[i]->pid, SIGKILL);
		i++;
	}
}
