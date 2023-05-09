/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:07 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/09 14:52:31 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define BUFFERSIZE 30

typedef struct player_data_s
{
	int	x;
	int	y;
}	t_player_data;

typedef struct data_tiles_s
{
	int				image_res;
	char			*player_xpm42;
	xpm_t			player_xpmt;
	mlx_image_t		player_image;
}	t_data_tiles;

typedef struct data_s
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				exit_count;
	int				collect_count;
	int				player_count;
	int				item_found;
	int				move_count;
	char			**map;
	t_player_data	data_player;
	t_data_tiles	data_tiles;
}	t_data;

/*ERROR MESSAGES */

# define MALLOC_ERROR "malloc() failed"

# define MLX_INIT_ERR "Failed to initialize mlx"
# define MLX_NEW_WINDOW_ERR "Failed to open a new window"

/* ARGUMENT VALIDATION */

# define INVALID_NBR_ARGS "Invalid number of arguments"
# define NULL_MAP "NULL map argument"

/* MAP VALIDATION */

# define INVALID_ENTITY "Invalid entity on map's file"
# define INVALID_FORMAT "Invalid map format"
# define MAP_NOT_CLOSED "Map is not closed by walls"
# define INVALID_NBR_EXIT "Invalid number of Exits (E)"
# define NO_COLLECTABLES "Map doesn't have any Collectable (C)"
# define INVALID_NBR_PLAYERS "Invalid number of Players on map (P)"

# define UNACHIEVABLE_ENTITIES "Map has unachievable entities"

/* READING MAP'S CONTENT */

# define INVALID_MAP_FILE "Invalid map file extension"
# define OPEN_MAP_FILE_ERR "Failed to open map's file"
# define EMPTY_MAP_FILE "Map file is empty"

/* XPM OPENING (les images connard) */

# define WALL_XPM_ERR "Failed to open wall image"
# define FLOOR_XPM_ERR "Failed to open floor image"
# define PLAYER_XPM_ERR "Failed to open player image"
# define COLLECTABLE_XPM_ERR "Failed to open collectable image"
# define EXIT_XPM_ERR "Failed to open exit image"

# define VOID '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECT 'C'
# define PLAYER 'P'

# define WIN_MESSAGE "YOU WON !"

//dans so_long.c
int		main(int argc, char **argv);

//dans check_map.c
void	parse_map(char *str, t_data *data);
void	check_map(int fd, t_data *data);
void	get_map(int fd, t_data *data);
int		check_char_map(char c, int x, int y, t_data *data);
void	check_nbr_char_map(t_data *data);

#endif