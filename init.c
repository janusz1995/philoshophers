
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
			return (0);
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
	all->forks = (pthread_mutex_t**)malloc(sizeof(pthread_mutex_t*) * all->counts_philo);
	if (!all->forks)
		return (0); // malloc error
	while (i < all->counts_philo)
	{
		if (!(all->forks[i] = malloc(sizeof(pthread_mutex_t))))
			return (free_forks(all, i));
		i++;
	}
	return (1);
}

void		init_struct(t_head_struct *all, int argc, char **argv)
{
	all->counts_philo = ft_atoi(argv[1]); // counts philoshophers
	all->time_to_die = ft_atoi(argv[2]); // time to die philo
	all->time_to_eat = ft_atoi(argv[3]); // time to eat
	all->time_to_sleep = ft_atoi(argv[4]); // time to sleep
	if (argc == 6)
		all->counts_to_need_eat = ft_atoi(argv[5]);
	else
		all->counts_to_need_eat = 0;
	all->counts_argc = argc;
	all->flag_die = 0;
	all->flag_eat = 0;
	all->finish_eat = 0;
	all->philo = malloc(sizeof(t_philosophers) * all->counts_philo);
	if (!all->philo)
	{
		return ; // malloc error
	}
	if (!init_forks(all))
	{
		return ; // malloc error
	}
	all->write_m = malloc(sizeof(pthread_mutex_t));
	if (!all->write_m)
	{
		return ; // malloc error
	}
	init_philophers(all);
	life_circle(all);
}