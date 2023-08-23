/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:18:00 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/23 14:03:25 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*life(void *args)
{
	t_data *data;
	int	i;

	data = (t_data *)args;
	i = data->n_thread;
	data->someone_died = 0;
	if (data->max_meals > 0)
	{
		while (data->max_meals > data->philo[i].meals_count
			&& data->someone_died == 0)
			philo_living(data, i);
	}
	else
	{
		while (data->someone_died == 0)
		{
			if (philo_living(data, i) == ERROR)
				break ;
		}
	}
	return (NULL);
}

int	hello_darkness_my_old_friend(t_data *data)
{
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (printf("Error:	mutex_init failed.\n"), ERROR);
	data->start_time = now();
	philo_print(data, 1, "has taken a  fork");
	philo_usleep(data->time_die);
	philo_print(data, 1, "died");
	philo_free(data);
	return (SUCCESS);
}


int	philo_living(t_data *data, int i)
{
	if (philo_eating(data, i) == ERROR)
		return (ERROR);
	if (data->max_meals != data->philo[i].meals_count)
	{
		if (philo_sleeping(data, i) == ERROR)
			return (ERROR);
		if (philo_thinking(data, i) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

void	*manager(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = 0;
	if (data->max_meals > 0)
	{
		while (data->max_meals > data->philo[i].meals_count
			&& data->someone_died == 0)
			if (philo_died(data, &i) == 1)
				break ;
	}
	else
	{
		while (data->someone_died == 0)
		{
			if (philo_died(data, &i) == 0)
				break ;
		}
	}
	return (NULL);
}
