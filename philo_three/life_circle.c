/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:00:29 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:00:38 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_died(void *tmp)
{
	t_philosophers	*philo;

	philo = (t_philosophers*)tmp;
	while (21)
	{
		if (philo->limit <= get_time())
		{
			sem_wait(philo->data->die_m);
			write_action(philo, DIE);
			exit(1);
		}
	}
	return ((void*)0);
}

int		life_circle(t_head_struct *all)
{
	int i;

	i = 0;
	all->start_time = get_time();
	while (i < all->counts_philo)
	{
		all->philo[i].pid = fork();
		if (all->philo[i].pid < 0)
			return (0);
		else if (all->philo[i].pid == 0)
		{
			eat_sleep_think(&all->philo[i]);
		}
		usleep(50);
		i++;
	}
	return (1);
}
