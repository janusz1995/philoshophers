/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:39:05 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:39:06 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	check_died(t_head_struct *all, int argc)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < all->counts_philo)
		{
			if (all->philo[i].limit <= get_time())
			{
				write_action(all->philo, DIE);
				all->flag_die = 1;
				break ;
			}
			if (argc == 6 && all->finish_eat == all->counts_philo)
			{
				all->flag_eat = 1;
				break ;
			}
			i++;
		}
		if (all->flag_die || all->flag_eat)
			break ;
	}
}

int				main(int argc, char **argv)
{
	struct s_head_struct	all;

	if (argc != 5 && argc != 6)
		return (error_arguments("Wrong number of arguments!\n"));
	if (!init_struct(&all, argc, argv))
		return (0);
	check_died(&all, argc);
	free_struct(&all);
	return (0);
}
