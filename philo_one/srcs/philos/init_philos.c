/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:48:56 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/02/01 22:19:29 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			init_forks(t_philo **philos)
{
	int		i;

	i = -1;
	while (++i < g_data.nb_philos)
	{
		if (!(philos[i]->left_fork = malloc(sizeof(pthread_mutex_t))))
			return (0);
		pthread_mutex_init(philos[i]->left_fork, NULL);
	}
	i = 0;
	while (i < g_data.nb_philos - 1)
	{
		philos[i]->right_fork = philos[i + 1]->left_fork;
		i++;
	}
	philos[i]->right_fork = philos[0]->left_fork;
	return (1);
}

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
	if (!init_forks(philos))
		return (NULL);
	gettimeofday(&(g_data.start_time), NULL);
	return (philos);
}
