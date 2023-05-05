/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/05 13:56:11 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	get_map(int fd, t_data *data)
{
	char	*buffer;
	char	*line;
	char	*temp_line;
	int		read_line;

	
}

void	check_map(int fd, t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	get_map(fd, data);
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
