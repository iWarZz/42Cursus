/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:07 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/12 13:35:53 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "tiles.h"
# include "map.h"

# define VOID '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTABLE 'C'
# define PLAYER 'P'

# define WIN_MESSAGE "YOU WON !"

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_map
{
	char		**map;
	int			rows; //lignes
	int			columns;
	int			collectables;
	int			exit;
	int			player;
	t_point		player_pos;
}	t_map;

typedef struct s_tiles
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectable;
	void	*exit;
}	t_tiles;

typedef struct s_game
{
	t_map	map;
	void	*mlx_ptr;
	void	*mlx_win;
	t_tiles	tiles;
	int		moves;
}	t_game;

static inline t_game	init_game(void)
{
	return ((t_game)
	{
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectables = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectable = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = -1,
	});
}

#endif