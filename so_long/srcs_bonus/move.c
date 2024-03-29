/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:13:12 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/12 10:07:38 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	solong_move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->data_player.x;
	y = data->data_player.y;
	if (data->map[x - 1][y] != WALL)
	{
		if (data->map[x - 1][y] == COLLECT)
		{
			data->collect_found_player++;
			data->map[x - 1][y] = VOID;
			solong_renderer(data, data->data_tiles.void_image, x - 1, y);
		}
		if (data->map[x][y] != EXIT)
			solong_renderer(data, data->data_tiles.void_image, x, y);
		else
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.playr_img, x - 1, y);
		data->data_player.x--;
		data->move_count++;
		solong_renderer(data, data->data_tiles.wall_image, 0, 0);
		mlx_put_string(data->mlx_ptr, ft_itoa(data->move_count), 0, 0);
	}
}

void	solong_move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->data_player.x;
	y = data->data_player.y;
	if (data->map[x + 1][y] != WALL)
	{
		if (data->map[x + 1][y] == COLLECT)
		{
			data->collect_found_player++;
			data->map[x + 1][y] = VOID;
			solong_renderer(data, data->data_tiles.void_image, x + 1, y);
		}
		if (data->map[x][y] != EXIT)
			solong_renderer(data, data->data_tiles.void_image, x, y);
		else
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.playr_img, x + 1, y);
		data->data_player.x++;
		data->move_count++;
		solong_renderer(data, data->data_tiles.wall_image, 0, 0);
		mlx_put_string(data->mlx_ptr, ft_itoa(data->move_count), 0, 0);
	}
}

void	solong_move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->data_player.x;
	y = data->data_player.y;
	if (data->map[x][y + 1] != WALL)
	{
		if (data->map[x][y + 1] == COLLECT)
		{
			data->collect_found_player++;
			data->map[x][y + 1] = VOID;
			solong_renderer(data, data->data_tiles.void_image, x, y + 1);
		}
		if (data->map[x][y] != EXIT)
			solong_renderer(data, data->data_tiles.void_image, x, y);
		else
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.playr_img, x, y + 1);
		data->data_player.y++;
		data->move_count++;
		solong_renderer(data, data->data_tiles.wall_image, 0, 0);
		mlx_put_string(data->mlx_ptr, ft_itoa(data->move_count), 0, 0);
	}
}

void	solong_move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->data_player.x;
	y = data->data_player.y;
	if (data->map[x][y - 1] != WALL)
	{
		if (data->map[x][y - 1] == COLLECT)
		{
			data->collect_found_player++;
			data->map[x][y - 1] = VOID;
			solong_renderer(data, data->data_tiles.void_image, x, y - 1);
		}
		if (data->map[x][y] != EXIT)
			solong_renderer(data, data->data_tiles.void_image, x, y);
		else
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.playr_img, x, y - 1);
		data->data_player.y--;
		data->move_count++;
		solong_renderer(data, data->data_tiles.wall_image, 0, 0);
		mlx_put_string(data->mlx_ptr, ft_itoa(data->move_count), 0, 0);
	}
}
