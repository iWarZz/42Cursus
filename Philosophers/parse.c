/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:33 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/21 10:22:12 by ssalor           ###   ########.fr       */
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