/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:27:03 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/22 12:50:59 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_free(t_data *data)
{
	free(data->philo);
	free(data->forks_mtx);
}

void	thread_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&data->forks_mtx[i]);
	pthread_mutex_destroy(&data->print_mtx);
}

int	philo_parsing(t_data *data, char **argv)
{
	if (ints_only(argv) == ERROR)
		return (ERROR);
	data->nbr_philo = (int)ft_atol(argv[1]);
	data->time_die = (int)ft_atol(argv[2]);
	data->time_eat = (int)ft_atol(argv[3]);
	data->time_sleep = (int)ft_atol(argv[4]);
	data->max_meals = -1;
	if (argv[5])
		data->max_meals = (int)ft_atol(argv[5]);
	if (data->nbr_philo <= 0 || data->nbr_philo > 200 || data->time_die <= 0
		|| data->time_eat <= 0 || data->time_sleep <= 0)
		return (ERROR);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (printf("Error:	Wrong argument count.\n"), 1);
	if (philo_parsing(&data, argv) == ERROR)
		return (printf("Error:	Wrong arguments.\n"), ERROR);
	if (philo_setup(&data) == ERROR)
		return (printf("Error:	Philo_setup failed.\n"), ERROR);
	if (forks_setup(&data) == ERROR)
		return (printf("Error:	Forks_setup failed.\n"), ERROR);
	if (data.nbr_philo == 1)
		return (hello_darkness_my_old_friend(&data));
	if (thread_setup(&data) == ERROR)
		return (printf("Error:	Thread_setup failed.\n"), ERROR);
	thread_free(&data);
	philo_free(&data);
	return (SUCCESS);
}
