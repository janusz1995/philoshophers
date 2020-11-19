/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:00:13 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:00:18 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_all_process(t_head_struct *all)
{
	int i;

	i = 0;
	while (i < all->counts_philo)
	{
		kill(all->philo[i].pid, SIGKILL);
		i++;
	}
	sem_post(all->die_m);
}
