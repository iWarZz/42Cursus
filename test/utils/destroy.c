/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:40:01 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/26 11:45:03 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	destroy_tiles(t_game *game)
{
	if (game->tiles.wall)
		mlx_delete_image(game->mlx_ptr, game->tiles.wall);
	if (game->tiles.floor)
		mlx_delete_image(game->mlx_ptr, game->tiles.floor);
	if (game->tiles.player)
		mlx_delete_image(game->mlx_ptr, game->tiles.player);
	if (game->tiles.collectable)
		mlx_delete_image(game->mlx_ptr, game->tiles.collectable);
	if (game->tiles.exit)
		mlx_delete_image(game->mlx_ptr, game->tiles.exit);
}

void	destroy(t_game *game)
{
	if (!game)
		return ;
	destroy_tiles(game);
	if (game->win_ptr)
	{
		mlx_close_window(game->mlx_ptr);
		mlx_close_window(game->win_ptr);
	}
	if (game->mlx_ptr)
	{
		mlx_terminate(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		free(game->map.map);
}
