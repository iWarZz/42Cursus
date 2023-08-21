/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:20:16 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/21 10:19:01 by ssalor           ###   ########.fr       */
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

//Dans utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long int ln, int fd);
int		ft_strlen(char *str);

#endif