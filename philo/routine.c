/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:05:18 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/23 14:30:42 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eating(t_data *data, int i)
{
	if (pthread_mutex_lock(&data->forks_mtx[data->philo[i].forks.left]) != 0)
		return (ERROR);
	if (philo_print(data, data->philo[i].id, "has taken a fork") == ERROR)
		return (ERROR);
	if (pthread_mutex_lock(&data->forks_mtx[data->philo[i].forks.right]) != 0)
		return (ERROR);
	if (philo_print(data, data->philo[i].id, "has taken a fork") == ERROR)
		return (ERROR);
	if (philo_print(data, data->philo[i].id, "is eating") == ERROR)
		return (ERROR);
	data->philo[i].time_left = now();
	philo_usleep(data->time_eat);
	if (pthread_mutex_unlock(&data->forks_mtx[data->philo[i].forks.left]) != 0)
		return (ERROR);
	if (pthread_mutex_unlock(&data->forks_mtx[data->philo[i].forks.right]) != 0)
		return (ERROR);
	data->philo[i].meals_count++;
	return (SUCCESS);
}

int	philo_sleeping(t_data *data, int i)
{
	if (philo_print(data, data->philo[i].id, "is sleeping") == ERROR)
		return (ERROR);
	philo_usleep(data->time_sleep);
	return (SUCCESS);
}

int	philo_thinking(t_data *data, int i)
{
	if (philo_print(data, data->philo[i].id, "is thinking") == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	philo_died(t_data *data, int *i)
{
	int	time;

	if (*i == data->nbr_philo)
		*i = 0;
	time = time_diff(data->philo[*i].time_left);
	if (time > data->time_die)
	{
		philo_print(data, data->philo[*i].id, "died");
		data->someone_died = 1;
		return (SUCCESS);
	}
	i++;
	return (ERROR);
}

void	philo_usleep(int ms)
{
	long int	start_time;

	start_time = 0;
	start_time = now();
	while ((now() - start_time) < (long int)ms)
		usleep(ms / 10);
}
