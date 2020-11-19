/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:38:59 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:39:01 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		init_forks_and_write(t_head_struct *all)
{
	int		i;

	i = 0;
	while (i < all->counts_philo)
		pthread_mutex_init(all->forks[i++], NULL);
	pthread_mutex_init(all->write_m, NULL);
}

int			init_philophers(t_head_struct *all)
{
	int		i;

	i = 0;
	init_forks_and_write(all);
	while (i < all->counts_philo)
	{
		all->philo[i].data = all;
		all->philo[i].eat_count = 0;
		if (!(all->philo[i].number_philo = ft_itoa(i + 1)))
		{
			free_id_philo(all, i);
			free_forks_and_philo(all, all->counts_philo);
			return (malloc_error("Malloc error :)\n"));
		}
		all->philo[i].left_fork = all->forks[i];
		if (i == 0)
			all->philo[i].right_fork = all->forks[all->counts_philo - 1];
		else
			all->philo[i].right_fork = all->forks[i - 1];
		i++;
	}
	return (1);
}

int			init_forks(t_head_struct *all)
{
	int		i;

	i = 0;
	all->forks = (pthread_mutex_t**)malloc(sizeof(pthread_mutex_t*)
													* all->counts_philo);
	if (!all->forks)
	{
		free(all->philo);
		return (malloc_error("Malloc error :)\n"));
	}
	while (i < all->counts_philo)
	{
		if (!(all->forks[i] = malloc(sizeof(pthread_mutex_t))))
		{
			ft_putstr_fd("Malloc error :)\n", 1);
			return (free_forks_and_philo(all, i));
		}
		i++;
	}
	return (1);
}

void		init_time_and_counts(t_head_struct *all, int argc, char **argv)
{
	all->counts_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->counts_to_need_eat = ft_atoi(argv[5]);
	else
		all->counts_to_need_eat = 0;
}

int			init_struct(t_head_struct *all, int argc, char **argv)
{
	init_time_and_counts(all, argc, argv);
	if (!(check_params(all)))
		return (0);
	all->counts_argc = argc;
	all->flag_die = 0;
	all->flag_eat = 0;
	all->finish_eat = 0;
	all->philo = malloc(sizeof(t_philosophers) * all->counts_philo);
	if (!all->philo)
		return (malloc_error("Malloc error :)\n"));
	if (!init_forks(all))
		return (malloc_error("Malloc error :)\n"));
	all->write_m = malloc(sizeof(pthread_mutex_t));
	if (!all->write_m)
	{
		ft_putstr_fd("Malloc error :)\n", 1);
		return (free_forks_and_philo(all, all->counts_philo));
	}
	init_philophers(all);
	life_circle(all);
	return (1);
}
