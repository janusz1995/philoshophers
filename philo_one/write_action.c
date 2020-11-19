/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:39:08 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:39:12 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_action(t_philosophers *philo, int type)
{
	if (!philo->data->flag_die)
	{
		pthread_mutex_lock(philo->data->write_m);
		ft_putnbr_fd(get_time() - philo->data->start_time, 1);
		write(1, "\t", 1);
		write(1, philo->number_philo, ft_strlen(philo->number_philo));
		if (type == TAKE_FORK)
			write(1, " has taken a fork\n", 18);
		else if (type == EAT)
			write(1, " is eating\n", 11);
		else if (type == SLEEP)
			write(1, " is sleeping\n", 13);
		else if (type == THINK)
			write(1, " is thinking\n", 13);
		else if (type == DIE)
			write(1, " died\n", 6);
		pthread_mutex_unlock(philo->data->write_m);
	}
}
