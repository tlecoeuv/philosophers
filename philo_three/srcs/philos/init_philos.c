/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:48:56 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/02/03 12:17:02 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo		*init_philo(int id)
{
	t_philo		*philo;

	if (!(philo = malloc(sizeof(t_philo))))
		return (NULL);
	philo->id = id;
	philo->nb_meal = 0;
	gettimeofday(&philo->last_meal, NULL);
	return (philo);
}

t_philo		**init_philos(void)
{
	t_philo		**philos;
	int			i;

	i = -1;
	if (!(philos = malloc(sizeof(t_philo *) * g_data.nb_philos)))
		return (NULL);
	while (++i < g_data.nb_philos)
		philos[i] = init_philo(i);
	gettimeofday(&(g_data.start_time), NULL);
	return (philos);
}
