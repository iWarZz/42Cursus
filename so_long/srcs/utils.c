/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:36:30 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/05 11:14:39 by ssalor           ###   ########.fr       */
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

void	can_play_map(t_data *data, int map_height, int map_width)
{
	int		**visited;
	int		i;

	i = 0;
	data->map_heigth = map_height;
	data->map_width = map_width;
	visited = malloc(sizeof(int *) * map_height);
	while (i < map_height)
		visited[i++] = ft_calloc(map_width, sizeof(int));
	solong_dfs(data->data_player.x, data->data_player.y, data, visited);
	i = 0;
	while (i < map_height)
	{
		free(visited[i]);
		visited[i] = NULL;
		i++;
	}
	free(visited);
	visited = NULL;
	if (data->coll_found_dfs != (data->collect_count + data->exit_count))
		exit(ft_printf(MAP_NOT_PLAYABLE));
	data->coll_found_dfs = 0;
}

void	solong_dfs(int x, int y, t_data *data, int **visited)
{
	visited[x][y] = 1;
	if (data->map[x][y] == COLLECT || data->map[x][y] == EXIT)
		data->coll_found_dfs++;
	if (data->map[x - 1][y] != WALL && !visited[x - 1][y])
		solong_dfs(x - 1, y, data, visited);
	if (data->map[x][y - 1] != WALL && !visited[x][y - 1])
		solong_dfs(x, y - 1, data, visited);
	if (data->map[x + 1][y] != WALL && !visited[x + 1][y])
		solong_dfs(x + 1, y, data, visited);
	if (data->map[x][y + 1] != WALL && !visited[x][y + 1])
		solong_dfs(x, y + 1, data, visited);
}
