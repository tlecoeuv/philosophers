/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:06:09 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/01/31 22:21:59 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	create_simulation(void)
{
	int		i;

	i = -1;
	if (!(g_simu.philos = malloc(sizeof(t_philo *) * g_simu.nb_philo)))
		return ;
	if (!(g_simu.forks = malloc(sizeof(pthread_mutex_t) * g_simu.nb_philo)))
		return ;
	while (++i < g_simu.nb_philo)
		pthread_mutex_init(&g_simu.forks[i], NULL);
	if (!(g_simu.philos[0] = malloc(sizeof(t_philo))))
		return ;
	g_simu.philos[0]->id = 0;
	gettimeofday(&g_simu.philos[0]->last_meal, NULL);
	g_simu.philos[0]->left_fork = &g_simu.forks[g_simu.nb_philo - 1];
	g_simu.philos[0]->right_fork = &g_simu.forks[0];
	i = 0;
	while (++i < g_simu.nb_philo)
	{
		if (!(g_simu.philos[i] = malloc(sizeof(t_philo))))
			return ;
		g_simu.philos[i]->id = i;
		gettimeofday(&g_simu.philos[i]->last_meal, NULL);
		g_simu.philos[i]->left_fork = &g_simu.forks[i - 1];
		g_simu.philos[i]->right_fork = &g_simu.forks[i];
	}
	gettimeofday(&g_simu.start_time, NULL);
	g_simu.running = 1;
	pthread_mutex_init(&g_simu.mutex_print, NULL);
	pthread_mutex_init(&g_simu.waiter, NULL);
}
