/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:57:21 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/01/31 22:25:03 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	check_run_cond(void)
{
	int		i;

	i = 0;
	if (g_simu.nb_must_eat != -1)
	{
		while (i < g_simu.nb_philo
							&& g_simu.philos[i]->nb_meal >= g_simu.nb_must_eat)
			i++;
		if (i == g_simu.nb_philo)
			g_simu.running = 0;
	}
	i = 0;
	while (i < g_simu.nb_philo)
	{
		if (get_ms_since(g_simu.philos[i]->last_meal)
												>=(uint64_t)g_simu.time_to_die)
		{
			print_action(g_simu.philos[i], "is dead");
			g_simu.running = 0;
		}
		i++;
	}
}

void	run_simulation(void)
{
	int		i;

	i = 0;
	while (i < g_simu.nb_philo)
	{
		pthread_create(&g_simu.philos[i]->th, NULL,
												&run_philo, g_simu.philos[i]);
		i+=2;
	}
	ms_sleep(1);
	i = 1;
	while (i < g_simu.nb_philo)
	{
		pthread_create(&g_simu.philos[i]->th, NULL,
												&run_philo, g_simu.philos[i]);
		i+=2;
	}
	i = 0;
	while (g_simu.running)
	{
		check_run_cond();
		usleep(500);
	}
	while (i < g_simu.nb_philo)
	{
		pthread_join(g_simu.philos[i]->th, NULL);
		i++;
	}
}
