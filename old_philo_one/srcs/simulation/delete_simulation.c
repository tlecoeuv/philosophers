/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:16:29 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/01/29 11:05:43 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	delete_simulation(void)
{
	int		i;

	i = 0;
	while (i < g_simu.nb_philo)
	{
		pthread_mutex_destroy(&g_simu.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&g_simu.mutex_print);
	free(g_simu.forks);
	free(g_simu.philos);
}
