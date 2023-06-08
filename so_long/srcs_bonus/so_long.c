/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:17:56 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/08 15:19:25 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	check_lose(t_data *data)
{
	int	x;
	int	y;
	int	v;
	int	w;

	x = data->data_player.x;
	y = data->data_player.y;
	v = data->data_enemy.v;
	w = data->data_enemy.w;
	if (x == v && y == w)
	{
		ft_printf("YOU LOSE NOOB");
		mlx_close_window(data->mlx_ptr);
	}
}

void	check_victory(t_data *data)
{
	int	x;
	int	y;

	x = data->data_player.x;
	y = data->data_player.y;
	if (data->map[x][y] == EXIT
			&& data->collect_found_player == data->collect_count)
	{
		mlx_close_window(data->mlx_ptr);
		ft_printf("You win with %i moves.\n", data->move_count);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit (ft_printf(INVALID_NBR_ARGS));
	solong_setup(&data);
	parse_map(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx_ptr = mlx_init(data.map_width * 64, data.map_heigth * 64,
			"HULK REVENGE", true);
	solong_loader(&data);
	solong_render_manager(&data);
	//ft_printf("Moves: %i\r", data.move_count);
	mlx_key_hook(data.mlx_ptr, (mlx_keyfunc) & solong_key_handler, &data);
	mlx_loop_hook(data.mlx_ptr, (void *) &check_victory, &data);
	mlx_loop_hook(data.mlx_ptr, (void *) &check_lose, &data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
}
