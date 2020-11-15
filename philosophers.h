

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define DIE 0
# define TAKE_FORKS 1
# define EAT	2
# define SLEEP 3
# define THINK 4
typedef  struct 			s_philoshophers
{
	char					*number_philo;
	uint64_t 				last_time_to_eat;
	uint64_t				limit;
	uint64_t				eat_count;
	struct s_head_struct	*data;
	pthread_t				id;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
} 							t_philosophers;

typedef	struct				s_head_struct
{
	pthread_mutex_t			**forks;
	pthread_mutex_t			*write_m;
	int						counts_philo;
	int 					time_to_die;
	int 					time_to_eat;
	int 					time_to_sleep;
	int 					counts_to_need_eat;
	int						flag_die;
	uint64_t				start_time;
	t_philosophers			*philo;
}							t_head_struct;

int			ft_atoi(const char *str);

uint64_t	get_time();

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

char		*ft_itoa(int c);

#endif
