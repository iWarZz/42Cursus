/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:57:00 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/05 11:58:55 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 1080 
#define HEIGHT 720

//static mlx_image_t* image;
static mlx_image_t* img;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);// IMPORTANT
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		img->instances[0].x += 5;
	//+ADD UN COMPTEUR
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "LOLOLOL", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(img = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	xpm_t* xpm = mlx_load_xpm42("resources/New-Piskel.xpm42");
	if (!xpm)
		error();
	
	// Convert texture to a displayable image
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 100, 100) < 0)
		error();
	

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_xpm42(xpm);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}