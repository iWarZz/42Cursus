/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:13:12 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/07 13:00:27 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

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
			solong_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.player_image, x - 1, y);
		data->data_player.x--;
		data->move_count++;
		ft_printf("Moves: %i\r", data->move_count);
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
			solong_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.player_image, x + 1, y);
		data->data_player.x++;
		data->move_count++;
		ft_printf("Moves: %i\r", data->move_count);
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
			solong_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.player_image, x, y + 1);
		data->data_player.y++;
		data->move_count++;
		ft_printf("Moves: %i\r", data->move_count);
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
			solong_renderer(data, data->data_tiles.exit_image, x, y);
		solong_renderer(data, data->data_tiles.player_image, x, y - 1);
		data->data_player.y--;
		data->move_count++;
		ft_printf("Moves: %i\r", data->move_count);
	}
}
