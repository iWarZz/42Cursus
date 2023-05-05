/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:56 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/05 13:10:14 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argv != 2)
		exit (ft_printf(INVALID_NBR_ARGS));
	parse_map(argv[1], &data);
}
