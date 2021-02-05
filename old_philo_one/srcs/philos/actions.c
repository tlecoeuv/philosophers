/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:49:44 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/01/31 22:31:48 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_action(t_philo *philo, char *action)
{
	uint64_t	time;

	time = get_ms_since(g_simu.start_time);
	if (g_simu.running == 1)
		printf("%8lu %d %s\n", time, philo->id, action);
}

void		philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ms_sleep(g_simu.time_to_sleep);
}

void		philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void		philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&g_simu.waiter);
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_unlock(&g_simu.waiter);
	print_action(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	ms_sleep(g_simu.time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
