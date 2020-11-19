/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:05:48 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 18:05:49 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			check_params(t_head_struct *all)
{
	if (all->counts_philo < 2 || all->time_to_die < 0 || all->time_to_eat < 0
		|| all->time_to_sleep < 0 || all->counts_to_need_eat < 0)
	{
		error_arguments("Wrong arguments\n");
		return (0);
	}
	return (1);
}
