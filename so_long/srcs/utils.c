/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:36:30 by ssalor            #+#    #+#             */
/*   Updated: 2023/05/10 14:37:09 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int		map_close_by_wall(char **map, int i)
{
	int	y;

	y = 0;
	while (map[0][y] && map[i - 1][y])
	{
		if (map[0][y] != WALL || map[i - 1][y] != WALL)
			return (0);
		y++;
	}
	y = 1;
	while (y < i - 1)
	{
		if (map[y][0] != WALL || map[y][ft_strlen(map[y]) - 1] != WALL)
			return (0);
			y++;
	}
	return (1);
}
