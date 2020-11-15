
#include "philosophers.h"

int 	error_arguments()
{
	write(1, "Wrong number of arguments!\n", 27);
	return (0);
}

int		main(int argc, char **argv)
{
	struct s_head_struct	all;

	if (argc != 5 && argc != 6)
		return (error_arguments());
	init_struct(&all, argc, argv);
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
	return (0);
}

//	timestamp_in_ms X has taken a fork
//	◦ timestamp_in_ms X is eating
//	◦ timestamp_in_ms X is sleeping
//	◦ timestamp_in_ms X is thinking
//	◦ timestamp_in_ms X died
