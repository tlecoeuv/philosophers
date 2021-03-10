/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:54:46 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/10 15:00:01 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data	g_data;

int		get_input(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 5 || (argc == 6 && ft_isnumber(argv[5])))
	{
		while (++i < 5)
			if (!ft_isnumber(argv[i]))
				return (0);
		if ((g_data.nb_philos = ft_atoi(argv[1])) < 2)
			return (0);
		g_data.time_to_die = ft_atoi(argv[2]);
		g_data.time_to_eat = ft_atoi(argv[3]);
		g_data.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			g_data.nb_must_eat = ft_atoi(argv[5]);
		else
			g_data.nb_must_eat = -1;
	}
	else
		return (0);
	pthread_mutex_init(&g_data.mutex_print, NULL);
	pthread_mutex_init(&g_data.waiter, NULL);
	g_data.running = 1;
	return (1);
}

void	destroy_philos_data(t_philo **philos)
{
	int		i;

	i = -1;
	while (++i < g_data.nb_philos)
	{
		pthread_mutex_destroy(philos[i]->left_fork);
		free(philos[i]->left_fork);
		free(philos[i]);
	}
	pthread_mutex_destroy(&g_data.waiter);
	pthread_mutex_destroy(&g_data.mutex_print);
}

int		main(int argc, char **argv)
{
	t_philo		**philos;

	if (get_input(argc, argv))
	{
		if ((philos = init_philos()))
		{
			run_philos(philos);
			destroy_philos_data(philos);
			free(philos);
		}
	}
}
