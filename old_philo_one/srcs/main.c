/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:48:28 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/01/26 20:16:00 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_simulation	g_simu;

int		get_input(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 5 || (argc == 6 && ft_isnumber(argv[5])))
	{
		while (++i < 5)
			if (!ft_isnumber(argv[i]))
				return (0);
		if ((g_simu.nb_philo = ft_atoi(argv[1])) < 2)
			return (0);
		g_simu.time_to_die = ft_atoi(argv[2]);
		g_simu.time_to_eat = ft_atoi(argv[3]);
		g_simu.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			g_simu.nb_must_eat = ft_atoi(argv[5]);
		else
			g_simu.nb_must_eat = -1;
	}
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	if (get_input(argc, argv))
	{
		create_simulation();
		run_simulation();
		delete_simulation();
	}
	else
		printf("bad arguments\n");
	return (0);
}
