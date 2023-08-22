/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:20:16 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/22 13:52:28 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR 1
# define SUCCESS 0

typedef struct forks
{
	int				left;
	int				right;
	int				lol;
}			t_forks;

typedef struct s_philo
{
	int				id;
	int				meals_count;
	long long		time_left;
	t_forks			forks;
	pthread_t		thread;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				someone_died;
	long long		start_time;
	int				n_thread;
	t_philo			*philo;
	pthread_t		manager;
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	print_mtx;
}			t_data;

//dans main.c
int		main(int argc, char **argv);
int		philo_parsing(t_data *data, char **argv);
void	thread_free(t_data *data);
void	philo_free(t_data *data);

//Dans utils.c
int			ints_only(char **str);
long		ft_atol(const char *str);
long long	now(void);
long long	time_diff(long long time);
int			philo_print(t_data *data, int id, char *msg);

//dans setup.c
int		philo_setup(t_data *data);
void	philo_push_data(t_data *data, int i, int j);
int		forks_setup(t_data *data);
int		thread_setup(t_data *data);
int		thread_join(t_data *data);

//dans routine.c

#endif