/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:07 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/06 13:50:47 by ssalor           ###   ########.fr       */
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
# include "libftprintf/srcs/ft_printf.h"

# define BUFFERSIZE 30

typedef struct player_data_s
{
	int	x;
	int	y;
}	t_player_data;

typedef struct data_tiles_s
{
	xpm_t			*player_xpmt;
	xpm_t			*wall_xpmt;
	xpm_t			*void_xpmt;
	xpm_t			*collect_xpmt;
	xpm_t			*exit_xpmt;
	mlx_image_t		*player_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*void_image;
	mlx_image_t		*collect_image;
	mlx_image_t		*exit_image;
}	t_data_tiles;

typedef struct data_s
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				image_width;
	int				image_heigth;
	int				exit_count;
	int				collect_count;
	int				player_count;
	int				item_found;
	int				move_count;
	char			**map;
	int				map_heigth;
	int				map_width;
	int				coll_found_dfs;
	int				collect_found_player;
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
# define MAP_NOT_PLAYABLE "Map is not playable"

/* XPM OPENING (les images connard) */

# define XPM_ERROR "Fail to load XPM"
# define IMAGE_ERROR "Fail to convert image to texture"

# define VOID '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECT 'C'
# define PLAYER 'P'

# define WIN_MESSAGE "YOU WON !"

//dans so_long.c
int		main(int argc, char **argv);
void	ft_hook(t_data *data);

//dans check_map.c
void	parse_map(char *str, t_data *data);
void	check_map(int fd, t_data *data);
void	get_map(int fd, t_data *data);
int		check_char_map(char c, int x, int y, t_data *data);
void	check_nbr_char_map(t_data *data);

//dans utils.c
int		map_close_by_wall(char **map, int i);
void	can_play_map(t_data *data, int map_height, int width);
void	solong_dfs(int x, int y, t_data *data, int **visited);
void	solong_setup(t_data *data);

//dans solong_loader
void	solong_render_manager(t_data *data);
void	solong_loader(t_data *data);
void	solong_double_renderer(t_data *data, mlx_image_t *img, int x, int y);
void	solong_renderer(t_data *data, mlx_image_t *img, int x, int y);

#endif