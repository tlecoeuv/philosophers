/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:37:28 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/10 15:05:46 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*routine(void *philo_ptr)
{
	t_philo		*philo;

	philo = philo_ptr;
	while (g_data.running &&
			(g_data.nb_must_eat == -1 || philo->nb_meal < g_data.nb_must_eat))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void		monitor_philos(t_philo **philos)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < g_data.nb_philos)
	{
		if ((get_ms_since(philos[i]->last_meal) >= (uint64_t)g_data.time_to_die)
				&& philos[i]->nb_meal != g_data.nb_must_eat)
		{
			print_action(philos[i], "is dead");
			g_data.running = 0;
		}
		if (philos[i]->nb_meal == g_data.nb_must_eat)
			count++;
		i++;
	}
	if (count == g_data.nb_philos)
		g_data.running = 0;
}

void		print_resume(t_philo **philos)
{
	int		i;

	i = 0;
	printf("\nRESUME:\n");
	while (i < g_data.nb_philos)
	{
		printf("id: %d nb_meal: %d \n", i, philos[i]->nb_meal);
		i++;
	}
}

void		run_philos(t_philo **philos)
{
	int		i;

	i = 0;
	while (i < g_data.nb_philos)
	{
		pthread_create(&philos[i]->th, NULL, &routine, philos[i]);
		i += 2;
	}
	ms_sleep(1);
	i = 1;
	while (i < g_data.nb_philos)
	{
		pthread_create(&philos[i]->th, NULL, &routine, philos[i]);
		i += 2;
	}
	while (g_data.running)
	{
		monitor_philos(philos);
		usleep(1000);
	}
	i = -1;
	while (++i < g_data.nb_philos)
		pthread_join(philos[i]->th, NULL);
}
