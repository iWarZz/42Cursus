/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:18:00 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/23 13:30:22 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



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
