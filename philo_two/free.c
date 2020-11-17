
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
}

int		free_forks_and_philo(t_head_struct *all, int len)
{
//	sem_close(all->eating_m);
//	sem_close(all->forks);
//	sem_close(all->write_m);
	free(all->philo);
	return (0);
}