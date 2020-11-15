
#include "philosophers.h"

int 	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int 	error_arguments()
{
	write(1, "Wrong number of arguments!\n", 27);
	return (0);
}

void	init_forks_and_write(t_head_struct *all)
{
	int	i;

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
		all->philo[i].eat_count = 0;
		all->philo[i].data = all;
		all->philo[i].last_time_to_eat = get_time();
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

void	write_action(t_philosophers *philo, int type)
{
	if (!philo->data->flag_die)
	{
		pthread_mutex_lock(philo->data->write_m);
		ft_putnbr_fd(get_time() - philo->data->start_time, 1);
		write(1,"\t" ,1);
		write(1, philo->number_philo, ft_strlen(philo->number_philo)); // num philo
		if (type == TAKE_FORKS)
			write(1, " has taken a forks\n", 19);
		else if (type == EAT)
			write(1, " is eating\n", 11);
		else if (type == SLEEP)
			write(1, " is sleeping\n", 13);
		else if (type == THINK)
			write(1, " is thinking\n", 13);
		else if (type == DIE)
			write(1, " died\n", 6);
		pthread_mutex_unlock(philo->data->write_m);
	}
}

void	eat(t_philosophers *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	write_action(philo, TAKE_FORKS);
	philo->last_time_to_eat = get_time();
	philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
	write_action(philo, EAT);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

//	timestamp_in_ms X has taken a fork
//	◦ timestamp_in_ms X is eating
//	◦ timestamp_in_ms X is sleeping
//	◦ timestamp_in_ms X is thinking
//	◦ timestamp_in_ms X died

}

void	*eat_sleep_think(void *tmp)
{
	t_philosophers *philo;

	philo = (t_philosophers*)tmp;

	if ((ft_atoi(philo->number_philo) % 2) == 0)
	while (21)
	{
		// need check die or no die philo!
		philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
//		if (philo->limit < get_time())
//		{
//			philo->data->flag_die = 1;
//			die(philo);
//		}
		if (philo->data->flag_die == 1)
			break ;
		eat(philo);
		usleep(philo->data->time_to_sleep * 1000);
		write_action(philo, THINK);

//		philo->last_time_to_eat = get_time();
//		philo->limit = philo->last_time_to_eat + g_all_params[1];
	}
	return ((void*)0);
}

void	life_circle(t_head_struct *all)
{
	int i;

	i = 0;
//	create while all philo
	while(i < all->counts_philo)
	{
		all->philo[i].last_time_to_eat = get_time();
		pthread_create(&all->philo[i].id, NULL, &eat_sleep_think, &all->philo[i]);
		i += 2;
	}

	i = 1;
	while(i < all->counts_philo)
	{
		all->philo[i].last_time_to_eat = get_time();
		pthread_create(&all->philo[i].id, NULL, &eat_sleep_think, &all->philo[i]);
		i += 2;
	}
	i = 0;
	while (i < all->counts_philo)
	{
		pthread_detach(all->philo[i].id);
		i++;
	}
//	i = 0;
//	while (i < all->counts_philo)
//	{
//		pthread_detach(all->philo[i].id);
//		i++;
//	}
}

int		free_forks(t_head_struct *all, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(all->forks[i]);
		i++;
	}
	free(all->forks);
	return (0);
}

int 	init_forks(t_head_struct *all)
{
	int i;

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

void 	init_struct(t_head_struct *all, int argc, char **argv)
{
	all->counts_philo = ft_atoi(argv[1]); // counts philoshophers
	all->time_to_die = ft_atoi(argv[2]); // time to die philo
	all->time_to_eat = ft_atoi(argv[3]); // time to eat
	all->time_to_sleep = ft_atoi(argv[4]); // time to sleep
	if (argc == 6)
	{
		all->counts_to_need_eat = ft_atoi(argv[5]);
	}
	all->flag_die = 0;
	all->start_time = get_time();
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
	// need life circle !!!!!
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
			if (all.philo[i].limit < get_time())
			{
				write_action(all.philo, DIE);
				all.flag_die = 1;
				break ;
			}
			i++;
		}
		if (all.flag_die)
			break ;
	}
	return (0);
}
