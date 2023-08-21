/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:27:03 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/21 10:28:21 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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