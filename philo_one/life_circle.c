/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:39:02 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:39:04 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	life_circle(t_head_struct *all)
{
	int i;

	i = 0;
	all->start_time = get_time();
	while (i < all->counts_philo)
	{
		pthread_create(&all->philo[i].id, NULL, &eat_sleep_think,
												&all->philo[i]);
		i++;
		usleep(50);
	}
}
