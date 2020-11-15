
#include "philosophers.h"

int		free_forks(t_head_struct *all, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(all->forks[i]);
		i++;
	}
	free(all->forks);
	return (0);
}