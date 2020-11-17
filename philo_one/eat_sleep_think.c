
#include "philosophers.h"

void	eat(t_philosophers *philo)
{
	size_t time;

	pthread_mutex_lock(philo->right_fork);
	write_action(philo, TAKE_FORK);
	pthread_mutex_lock(philo->left_fork);
	write_action(philo, TAKE_FORK);
	philo->last_time_to_eat = get_time();
	philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
	write_action(philo, EAT);
	time = get_time();
	while (get_time() <= time + philo->data->time_to_eat)
		usleep(100);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->data->counts_argc == 6)
		philo->eat_count++;
}

void	*eat_sleep_think(void *tmp)
{
	t_philosophers	*philo;
	size_t			time;

	philo = (t_philosophers*)tmp;
	philo->last_time_to_eat = get_time();
	philo->limit = philo->last_time_to_eat + philo->data->time_to_die;
	while (21)
	{
		if (philo->data->flag_die == 1 || philo->data->flag_eat == 1)
			break ;
		eat(philo);
		if (philo->eat_count == philo->data->counts_to_need_eat && philo->data->counts_argc == 6)
		{
			philo->data->finish_eat++;
			break ;
		}
		write_action(philo, SLEEP);
		time = get_time();
		while (get_time() <= time + philo->data->time_to_sleep)
			usleep(100);
		write_action(philo, THINK);
	}
	return ((void*)0);
}