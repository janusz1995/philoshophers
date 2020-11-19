/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:38:35 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:38:37 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_id_philo(t_head_struct *all, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(all->philo[i].number_philo);
		i++;
	}
}

void	free_struct(t_head_struct *all)
{
	free_id_philo(all, all->counts_philo);
	free_forks_and_philo(all, all->counts_philo);
	if (all->write_m)
		free(all->write_m);
}

int		free_forks_and_philo(t_head_struct *all, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(all->forks[i]);
		i++;
	}
	free(all->forks);
	free(all->philo);
	return (0);
}
