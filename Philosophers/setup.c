/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:46:24 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/22 12:47:29 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_setup(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	data->philo = malloc(sizeof(t_philo) * (data->nbr_philo + 1));
	if (data->philo == NULL)
		return (ERROR);
	while (j < data->nbr_philo)
		philo_push_data(data, i++, j++);
	philo_push_data(data, i, 0);
	return (SUCCESS);
}

void	philo_push_data(t_data *data, int i, int j)
{
		data->philo[i].id = i + 1;
		data->philo[i].meals_count = 0;
		data->philo[i].time_left = 0;
		data->philo[i].forks.left = i;
		data->philo[i].forks.right = j;
		data->philo[i].data = data;
}

int	forks_setup(t_data *data)
{
	int	i;

	i = 0;
	data->forks_mtx = malloc(sizeof(pthread_mutex_t) * data->nbr_philo + 1);
	if (data->forks_mtx == NULL)
		return (ERROR);
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks_mtx[i], NULL) != 0)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	thread_setup(t_data *data)
{
	int	i;

	i = 0;
	data->someone_died = 0;
	data->start_time = now();
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (ERROR);
	while (i < data->nbr_philo)
	{
		data->n_thread = i;
		if (pthread_create(&data->philo[i].thread, NULL,
				&life, (void *) data) != 0)
			return (ERROR);
		i++;
		philo_usleep(1000);
	}
	if (pthread_create(&data->manager, NULL, &manager, (void *) data) != 0)
		return (ERROR);
	philo_usleep(1000);
	if (thread_join(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	thread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (ERROR);
		i++;
	}
	if (pthread_join(data->manager, NULL) != 0)
		return (ERROR);
	return (SUCCESS);
}