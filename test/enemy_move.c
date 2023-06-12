/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:47:28 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/12 09:23:51 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

//coord player == px et py

void	solong_enemy_move_up(t_data *data)
{
	int	x;
	int	y;
	int	px;
	int	py;
	
	x = data->data_enemy.v;
	y = data->data_enemy.w;
	px = data->data_player.x;
	py = data->data_player.y;
	if (data->map[x - 1][y] != WALL)
	{
		if (data->map[x][y] == EXIT)
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		else if (data->map[x][y] == COLLECT)
			solong_double_renderer(data, data->data_tiles.collect_image, x, y);
		else
			solong_renderer(data, data->data_tiles.void_image, x, y);
		solong_renderer(data, data->data_tiles.enemy_image, x - 1, y);
		data->data_enemy.v--;
	}
}

void	solong_enemy_move_down(t_data *data)
{
	int	x;
	int	y;
	int	px;
	int	py;
	
	x = data->data_enemy.v;
	y = data->data_enemy.w;
	px = data->data_player.x;
	py = data->data_player.y;
	if (data->map[x + 1][y] != WALL)
	{
		if (data->map[x][y] == EXIT)
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		else if (data->map[x][y] == COLLECT)
			solong_double_renderer(data, data->data_tiles.collect_image, x, y);
		else
			solong_renderer(data, data->data_tiles.void_image, x, y);
		solong_renderer(data, data->data_tiles.enemy_image, x + 1, y);
		data->data_enemy.v++;
	}
}

void	solong_enemy_move_right(t_data *data)
{
	int	x;
	int	y;
	int	px;
	int	py;
	
	x = data->data_enemy.v;
	y = data->data_enemy.w;
	px = data->data_player.x;
	py = data->data_player.y;
	if (data->map[x][y + 1] != WALL)
	{
		if (data->map[x][y] == EXIT)
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		else if (data->map[x][y] == COLLECT)
			solong_double_renderer(data, data->data_tiles.collect_image, x, y);
		else
			solong_renderer(data, data->data_tiles.void_image, x, y);
		solong_renderer(data, data->data_tiles.enemy_image, x, y + 1);
		data->data_enemy.w++;
	}
}

void	solong_enemy_move_left(t_data *data)
{
	int	x;
	int	y;
	int	px;
	int	py;
	
	x = data->data_enemy.v;
	y = data->data_enemy.w;
	px = data->data_player.x;
	py = data->data_player.y;
	if (data->map[x][y - 1] != WALL)
	{
		if (data->map[x][y] == EXIT)
			solong_double_renderer(data, data->data_tiles.exit_image, x, y);
		else if (data->map[x][y] == COLLECT)
			solong_double_renderer(data, data->data_tiles.collect_image, x, y);
		else
			solong_renderer(data, data->data_tiles.void_image, x, y);
		solong_renderer(data, data->data_tiles.enemy_image, x, y - 1);
		data->data_enemy.w--;
	}
}
