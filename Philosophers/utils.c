/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:35:31 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/22 12:58:20 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ints_only(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (ERROR);
			j++;
		}
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

long long	now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	time_diff(long long time)
{
	if (time > 0)
		return (now() - time);
	return (0);
}

int	philo_print(t_data *data, int id, char *msg)
{
	long long	now;

	now = time_diff(data->start_time);
	if (data->someone_died == 1)
		return (ERROR);
	pthread_mutex_lock(&data->print_mtx);
	if (data->someone_died == 1)
	{
		pthread_mutex_unlock(&data->print_mtx);
		return (ERROR);
	}
	else
		printf("%lld %i %s\n", now, id, msg);
	pthread_mutex_unlock(&data->print_mtx);
	return (SUCCESS);
}