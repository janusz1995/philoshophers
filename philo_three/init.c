/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:59:59 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:00:07 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		init_forks_and_write(t_head_struct *all)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/eating");
	sem_unlink("/die");
	all->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, all->counts_philo);
	all->eating_m = sem_open("/eating", O_CREAT | O_EXCL, 0644,
														all->counts_philo / 2);
	all->write_m = sem_open("/write", O_CREAT | O_EXCL, 0644, 1);
	all->die_m = sem_open("/die", O_CREAT | O_EXCL, 0644, 1);
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
		i++;
	}
	return (1);
}

int			check_params(t_head_struct *all)
{
	if (all->counts_philo < 2 || all->time_to_die < 130 || all->time_to_eat < 0
			|| all->time_to_sleep < 0 || all->counts_to_need_eat < 0)
	{
		error_arguments("Wrong arguments\n");
		return (0);
	}
	return (1);
}

int			init_struct(t_head_struct *all, int argc, char **argv)
{
	all->counts_philo = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->counts_to_need_eat = ft_atoi(argv[5]);
	else
		all->counts_to_need_eat = 0;
	if (!(check_params(all)))
		return (0);
	all->finish_eat = 0;
	all->philo = malloc(sizeof(t_philosophers) * all->counts_philo);
	if (!all->philo)
		return (malloc_error("Malloc error :)\n"));
	init_philophers(all);
	if (!life_circle(all))
		return (0);
	return (1);
}
