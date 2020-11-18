
#include "philosophers.h"

void	kill_all_precess(t_head_struct *all)
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


int		main(int argc, char **argv)
{
	int		status;

	struct s_head_struct	all;
	if (argc != 5 && argc != 6)
		return (error_arguments("Wrong number of arguments!\n"));
	if (!init_struct(&all, argc, argv))
		return (0);
	waitpid(-1, &status, 0);
	status = WEXITSTATUS(status);
	if (status == 1)
		kill_all_precess(&all);
	if (status == 2)
	{
		all.finish_eat++;
		if (all.finish_eat == all.counts_philo)
			kill_all_precess(&all);
	}
	free_struct(&all);
	return (0);
}

//	timestamp_in_ms X has taken a fork
//	◦ timestamp_in_ms X is eating
//	◦ timestamp_in_ms X is sleeping
//	◦ timestamp_in_ms X is thinking
//	◦ timestamp_in_ms X died
