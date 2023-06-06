/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:56 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/06 14:41:09 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	ft_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_ptr);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		data->data_tiles.player_image->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		data->data_tiles.player_image->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		data->data_tiles.player_image->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		data->data_tiles.player_image->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
		exit (ft_printf(INVALID_NBR_ARGS));
	solong_setup(&data);
	parse_map(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx_ptr = mlx_init(data.map_width * 64, data.map_heigth * 64, "HULK REVENGE", true);
	solong_loader(&data);
	solong_render_manager(&data);
	mlx_loop_hook(data.mlx_ptr, (void *) ft_hook, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
}
