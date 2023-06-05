/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:56 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/05 14:39:04 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argv != 2)
		exit (ft_printf(INVALID_NBR_ARGS));
	parse_map(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx_ptr = mlx_init(data.map_width * 64, data.map_heigth * 64, "HULK REVENGE", true);
	solong_loader(&data);
	solong_render_manager(&data);
}
