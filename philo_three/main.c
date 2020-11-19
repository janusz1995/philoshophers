/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:00:46 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:00:50 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		main(int argc, char **argv)
{
	int						status;
	struct s_head_struct	all;

	if (argc != 5 && argc != 6)
		return (error_arguments("Wrong number of arguments!\n"));
	if (!init_struct(&all, argc, argv))
		return (0);
	waitpid(-1, &status, 0);
	status = WEXITSTATUS(status);
	if (status == 1)
		kill_all_process(&all);
	if (status == 2)
	{
		all.finish_eat++;
		if (all.finish_eat == all.counts_philo)
			kill_all_process(&all);
	}
	free_struct(&all);
	return (0);
}
