/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:46:39 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/15 17:26:10 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_action(t_philo *philo, char *action)
{
	uint64_t	time;

	time = get_ms_since(g_data.start_time);
	if (g_data.running == 1)
		printf("%8llu %d %s\n", time, philo->id, action);
}

void		philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ms_sleep(g_data.time_to_sleep);
}

void		philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void		take_fork(t_philo *philo)
{
	if ((g_data.nb_philos % 2) == 0)
	{
		if ((philo->id % 2) == 0)
		{
			pthread_mutex_lock(philo->right_fork);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(philo->left_fork);
			print_action(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			print_action(philo, "has taken a fork");
			pthread_mutex_lock(philo->right_fork);
			print_action(philo, "has taken a fork");
		}
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void		philo_eat(t_philo *philo)
{
	take_fork(philo);
	print_action(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	ms_sleep(g_data.time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
