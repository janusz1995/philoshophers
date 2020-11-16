
#include "philosophers.h"

int		main(int argc, char **argv)
{
	struct s_head_struct	all;

	if (argc != 5 && argc != 6)
		return (error_arguments("Wrong number of arguments!\n"));
	if (!init_struct(&all, argc, argv))
		return (0);
	while (1)
	{
		int i = 0;
		while (i < all.counts_philo)
		{
			if (all.philo[i].limit <= get_time())
			{
				write_action(all.philo, DIE);
				all.flag_die = 1;
				break ;
			}
			if (argc == 6 && all.finish_eat == all.counts_philo)
			{
				all.flag_eat = 1;
				break ;
			}
			i++;
		}
		if (all.flag_die || all.flag_eat)
			break ;
	}
	free_struct(&all);
	return (0);
}

//	timestamp_in_ms X has taken a fork
//	◦ timestamp_in_ms X is eating
//	◦ timestamp_in_ms X is sleeping
//	◦ timestamp_in_ms X is thinking
//	◦ timestamp_in_ms X died
