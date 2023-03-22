/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:17:46 by ssalor            #+#    #+#             */
/*   Updated: 2023/03/22 15:02:34 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_ctob(unsigned char c, int pid)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = 1 << i;
		if (c & bit)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(500);
		i--;
	}
}

void	ft_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		ft_ctob(str[i++], pid);
	ft_ctob('\0', pid);
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		ft_text(av[2], server_pid);
	}
	else
	{
		write(1, "Error:\n", 8);
		return (-1);
	}
	return (0);
}
