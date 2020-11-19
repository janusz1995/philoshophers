/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:20:39 by drina             #+#    #+#             */
/*   Updated: 2020/11/19 17:20:41 by drina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define DIE 0
# define TAKE_FORK 1
# define EAT	2
# define SLEEP 3
# define THINK 4

typedef	struct				s_philoshophers
{
	char					*number_philo;
	int						eat_count;
	uint64_t				limit;
	uint64_t				last_time_to_eat;
	pthread_t				id;
	struct s_head_struct	*data;
}							t_philosophers;

typedef	struct				s_head_struct
{
	int						flag_die;
	int						flag_eat;
	int						finish_eat;
	int						counts_argc;
	int						time_to_eat;
	int						time_to_die;
	int						counts_philo;
	int						time_to_sleep;
	int						counts_to_need_eat;
	uint64_t				start_time;
	t_philosophers			*philo;
	sem_t					*eating_m;
	sem_t					*forks;
	sem_t					*write_m;
}							t_head_struct;

int							error_arguments();
int							malloc_error(char *str);
int							ft_atoi(const char *str);
int							ft_strlen(const char *str);
int							free_forks_and_philo(t_head_struct *all, int len);
int							init_struct(t_head_struct *all, int argc,
																char **argv);
uint64_t					get_time();
void						*eat_sleep_think(void *tmp);
void						ft_putnbr_fd(int n, int fd);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						life_circle(t_head_struct *all);
void						free_struct(t_head_struct *all);
void						free_id_philo(t_head_struct *all, int len);
void						write_action(t_philosophers *philo, int type);
char						*ft_itoa(int c);

#endif
