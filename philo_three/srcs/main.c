/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:54:46 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/11 17:30:19 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_data	g_data;

void	init_semaphores(void)
{
	sem_unlink("print");
	sem_unlink("waiter");
	sem_unlink("forks");
	sem_unlink("philo die");
	sem_unlink("meals done");
	g_data.sem_print = sem_open("print", O_CREAT | O_RDWR, 0660, 1);
	g_data.waiter = sem_open("waiter", O_CREAT | O_RDWR, 0660, 1);
	g_data.forks = sem_open("forks", O_CREAT | O_RDWR, 0660, g_data.nb_philos);
	g_data.philo_die = sem_open("philo die", O_CREAT | O_RDWR, 0660, 0);
	g_data.meals_done = sem_open("meals done", O_CREAT | O_RDWR, 0660, 0);
}

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
	g_data.running = 1;
	init_semaphores();
	return (1);
}

void	destroy_philos_data(t_philo **philos)
{
	int		i;

	i = -1;
	while (++i < g_data.nb_philos)
		free(philos[i]);
	sem_close(g_data.forks);
	sem_close(g_data.sem_print);
	sem_close(g_data.waiter);
	sem_close(g_data.philo_die);
	sem_close(g_data.meals_done);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("waiter");
	sem_unlink("philo die");
	sem_unlink("meals done");
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
