/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:58:40 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 16:58:45 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philosophers *philo)
{
	size_t time;

	sem_wait(philo->data->eating_m);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	write_action(philo, TAKE_FORK);
	write_action(philo, TAKE_FORK);
	philo->last_time_to_eat = get_time();
	philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
	write_action(philo, EAT);
	time = get_time();
	while (get_time() <= time + philo->data->time_to_eat)
		usleep(100);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	sem_post(philo->data->eating_m);
	if (++philo->eat_count == philo->data->counts_to_need_eat)
		exit(2);
}

void	eat_sleep_think(t_philosophers *philo)
{
	size_t			time;

	philo->last_time_to_eat = get_time();
	philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
	pthread_create(&philo->id, NULL, &check_died, philo);
	while (21)
	{
		sem_wait(philo->data->die_m);
		sem_post(philo->data->die_m);
		eat(philo);
		write_action(philo, SLEEP);
		time = get_time();
		while (get_time() <= time + philo->data->time_to_sleep)
			usleep(100);
		write_action(philo, THINK);
	}
}
