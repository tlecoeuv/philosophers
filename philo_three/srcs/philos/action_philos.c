/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:46:39 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/11 15:58:46 by tlecoeuv         ###   ########.fr       */
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

void		print_action(t_philo *philo, char *action)
{
	uint64_t	time;

	time = get_ms_since(g_data.start_time);
	if (g_data.running == 1)
		printf("%8lu %d %s\n", time, philo->id, action);
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

void		philo_eat(t_philo *philo)
{
	sem_wait(g_data.waiter);
	sem_wait(g_data.forks);
	print_action(philo, "has taken a fork");
	sem_wait(g_data.forks);
	print_action(philo, "has taken a fork");
	sem_post(g_data.waiter);
	print_action(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	philo->nb_meal++;
	ms_sleep(g_data.time_to_eat);
	sem_post(g_data.forks);
	sem_post(g_data.forks);
}
