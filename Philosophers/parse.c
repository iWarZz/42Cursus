/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:32:33 by ssalor            #+#    #+#             */
/*   Updated: 2023/08/18 13:54:35 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	numeric(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_p *p)
{
	if ((ac == 5 || ac == 6) && numeric(av, 0, 1))
	{
		p->a.total = ft_atoi(av[1]);
		p->a.die = ft_atoi(av[2]);
		p->a.eat = ft_atoi(av[3]);
		p->a.sleep = ft_atoi(av[4]);
		p->a.m_eat = -1;
		if (ac == 6)
			p->a.m_eat = ft_atoi(av[5]);
		if (p->a.total <= 0 || p->a.eat <= 0 || p->a.sleep <= 0 || p->a.die)
			return (0);
		return (1);
	}
	return (0);
}
