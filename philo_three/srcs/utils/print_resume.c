/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_resume.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:45:40 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/02/25 16:46:06 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_resume(t_philo **philos)
{
	int		i;

	i = 0;
	printf("\nRESUME:\n");
	while (i < g_data.nb_philos)
	{
		printf("id: %d nb_meal: %d \n", i, philos[i]->nb_meal);
		i++;
	}
}
