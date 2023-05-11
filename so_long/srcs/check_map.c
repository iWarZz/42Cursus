/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/11 11:13:24 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_nbr_char_map(t_data *data)
{
	if (data->collect_count <= 0)
		exit (ft_printf(NO_COLLECTABLES));
	if (data->player_count != 1)
		exit (ft_printf(INVALID_NBR_PLAYERS));
	if (data->exit_count != 1)
		exit (ft_printf(INVALID_NBR_EXIT));
}

int		check_char_map(char c, int x, int y, t_data *data)
{
	if (c == VOID || c == WALL || c == EXIT || c == COLLECT || c == PLAYER)
	{
		if (c == COLLECT)
			data->collect_count++;
		if (c == EXIT)
			data->exit_count++;
		if (c == PLAYER)
		{
			data->player_count++;
			data->data_player.x = x;
			data->data_player.y = y;
		}
		return (1);
	}
	return (0);
}

void	get_map(int fd, t_data *data)
{
	char	*buffer;
	char	*line;
	char	*line_tmp;
	int		read_length;

	read_length = 1;
	line = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	while (read_length > 0)
	{
		read_length = read(fd, buffer, BUFFERSIZE);
		if (read_length < 0)
			data->map = NULL;
		buffer[read_length] = '\0';
		line_tmp = line;
		line = ft_strjoin(line, buffer);
		free(line_tmp);
		if (read_length == 0)
			data->map = ft_split(line, '\n');
		free(buffer);
		buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	}
	free(buffer);
	free(line);
	close(fd);
}

void	check_map(int fd, t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	get_map(fd, data);
	if (!data->map)
		exit (ft_printf(EMPTY_MAP_FILE));
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[0]))
			exit (ft_printf(INVALID_FORMAT));
		while (data->map[i][y])
		{
			if (!check_char_map(data->map[i][y], i, y, data));
				exit (ft_printf(INVALID_ENTITY));
			y++;
		}
		i++;
	}
	check_nbr_char_map(data);
	if (!map_close_by_wall(data->map, i));
		exit (ft_printf(MAP_NOT_CLOSED));
	can_play_map();
}

void	parse_map(char *str, t_data *data)
{
	char	*extension;
	int		fd;
	
	extension = ft_substr(str, ft_strlen(str) - 4, 4);
	if (ft_strncmp(extension, ".ber", 4) != 0)
	{
		free (extension);
		exit (ft_printf(INVALID_MAP_FILE));
	}
	else
	{
		free (extension);
		fd = open (str, O_RDONLY);
		if (fd == -1)
			exit (ft_printf(OPEN_MAP_FILE_ERR));
		check_map(fd, data);
	}
}
