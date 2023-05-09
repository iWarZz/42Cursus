/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/09 14:19:06 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

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
		exit (ft_printf("JE SAIS PAS QUOI METTRE"))
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[0]))
			exit (ft_printf(INVALID_FORMAT));
		while (data->map[i][y])
		{
			
		}
	}
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
