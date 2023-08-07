/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:20:16 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/02 14:08:11 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
int						total;
int						die;
int						eat;
int						sleep;
int						m_eat;
long int				start_t;
pthread_mutex_t			write_mutex;
pthread_mutex_t			dead;
pthread_mutex_t			time_eat;
pthread_mutex_t			finish;
int						nb_p_finish;
int						stop;
}						t_arg;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_t			thread_death_id;
	pthread_mutex_t		*r_f;
	pthread_mutex_t		l_f;
	t_arg				*pa;
	long int			ms_eat;
	unsigned int		nb_eat;
	int					finish;
}						t_philo;

typedef struct s_p
{
	t_philo				*ph;
	t_arg				a;
}						t_p;

//Dans utils.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long int ln, int fd);
int		ft_strlen(char *str);

#endif