/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:48:33 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/15 17:22:04 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*monitor_nb_meals(void *useless)
{
	int nb_philos_end;

	(void)useless;
	nb_philos_end = 0;
	while (g_data.running && nb_philos_end < g_data.nb_philos)
	{
		sem_wait(g_data.meals_done);
		nb_philos_end++;
		ms_sleep(1);
	}
	g_data.running = 0;
	return (NULL);
}

void		post_nb_meals_reached(t_philo *philo)
{
	static int already_post = 0;

	if (already_post == 1)
		return ;
	if (g_data.nb_must_eat == -1)
		return ;
	if (philo->nb_meal < g_data.nb_must_eat)
		return ;
	sem_post(g_data.meals_done);
	already_post = 1;
}

void		*monitor_dead(void *useless)
{
	(void)useless;
	sem_wait(g_data.philo_die);
	g_data.running = 0;
	return (NULL);
}

void		post_dead(t_philo *philo)
{
	if ((get_ms_since(philo->last_meal) >= (uint64_t)g_data.time_to_die))
	{
		print_action(philo, "is dead");
		sem_post(g_data.philo_die);
		g_data.running = 0;
	}
}
