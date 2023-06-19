/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:09:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/19 13:42:39 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**arg_values;
	
	a = NULL;
	b = NULL;
	if ((argc == 1) || argc == 2 && !argv[1][0])
		exit(ft_printf(NO_ARG));
	else if (argc == 2)
		arg_values = ft_split(argv[1], ' ');
	else
		arg_values = argv + 1;
	create_stack(&a, arg_values);
}
