/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:12:13 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/12 14:42:46 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

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

#endif

