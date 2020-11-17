
#include "philosophers.h"

void	life_circle(t_head_struct *all)
{
	int i;

	i = 0;
	all->start_time = get_time();
	while(i < all->counts_philo)
	{
		pthread_create(&all->philo[i].id, NULL, &eat_sleep_think, &all->philo[i]);
		i++;
		usleep(50);
	}
}
