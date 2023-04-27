/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/27 14:07:56 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_map(int fd)
{
	
}

void	parse_map(char *str)
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
		check_map(fd);
	}
}
