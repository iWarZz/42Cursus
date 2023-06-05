/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:03:02 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/05 14:37:25 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	solong_renderer(t_data *data, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(data->mlx_ptr, img, y * 64, x * 64);
}


void	solong_double_renderer(t_data *data, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(data->mlx_ptr, data->data_tiles.void_image,
		 y * 64, x * 64);
	mlx_image_to_window(data->mlx_ptr, img, y * 64, x * 64);
}

void	solong_render_manager(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == WALL)
				solong_renderer(data, data->data_tiles.wall_image, x, y);
			if (data->map[x][y] == VOID)
				solong_renderer(data, data->data_tiles.void_image, x, y);
			if (data->map[x][y] == COLLECT)
				solong_double_renderer(data, data->data_tiles.collect_image, x, y);
			if (data->map[x][y] == PLAYER)
				solong_double_renderer(data, data->data_tiles.player_image, x, y);
			if (data->map[x][y] == EXIT)
				solong_renderer(data, data->data_tiles.exit_image, x, y);
		}
	}
}

void	solong_loader(t_data *data)
{
	data->data_tiles.wall_xpmt = mlx_load_xpm42("../XPM42/wall.xpm42");
	data->data_tiles.void_xpmt = mlx_load_xpm42("../XPM42/sol.xpm42");
	data->data_tiles.collect_xpmt = mlx_load_xpm42("../XPM42/collect.xpm42");
	data->data_tiles.player_xpmt = mlx_load_xpm42("../XPM42/hulk_petit.xpm42");
	data->data_tiles.exit_xpmt = mlx_load_xpm42("../XPM42/exit.xpm42");
	if (!data->data_tiles.wall_xpmt || !data->data_tiles.void_xpmt
		|| !data->data_tiles.collect_xpmt || !data->data_tiles.player_xpmt
		|| !data->data_tiles.exit_xpmt)
		exit(ft_printf(XPM_ERROR));
	data->data_tiles.wall_image = mlx_texture_to_image(data->mlx_ptr,
			&data->data_tiles.wall_xpmt->texture);
	data->data_tiles.void_image = mlx_texture_to_image(data->mlx_ptr,
			&data->data_tiles.void_xpmt->texture);
	data->data_tiles.collect_image = mlx_texture_to_image(data->mlx_ptr,
			&data->data_tiles.collect_xpmt->texture);
	data->data_tiles.player_image = mlx_texture_to_image(data->mlx_ptr,
			&data->data_tiles.player_xpmt->texture);
	data->data_tiles.exit_image = mlx_texture_to_image(data->mlx_ptr,
			&data->data_tiles.exit_xpmt->texture);
	if (!data->data_tiles.wall_image || !data->data_tiles.void_image
		|| !data->data_tiles.collect_image || !data->data_tiles.player_image
		|| !data->data_tiles.exit_image)
		exit(ft_printf(IMAGE_ERROR));
}

