/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlecoeuv <tlecoeuv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:34:47 by tlecoeuv          #+#    #+#             */
/*   Updated: 2021/03/15 17:37:00 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		ms_sleep(uint64_t t_ms)
{
	uint64_t	start_sleep_time;

	start_sleep_time = get_ms_since(g_data.start_time);
	while (get_ms_since(g_data.start_time) - start_sleep_time < t_ms)
	{
		usleep(500);
	}
}

uint64_t	get_ms_since(struct timeval time)
{
	struct timeval	now;
	struct timeval	diff;
	uint64_t		diff_ms;

	gettimeofday(&now, NULL);
	diff.tv_sec = now.tv_sec - time.tv_sec;
	diff.tv_usec = now.tv_usec - time.tv_usec;
	diff_ms = (diff.tv_sec * 1000) + (diff.tv_usec / 1000);
	return (diff_ms);
}
