/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:27:03 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/18 13:56:15 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_p		p;

	if (!(parse_args(ac, av, &p)))
		return(ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (ft_exit("Malloc return NULL\n"));
	if (!initialize(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
}