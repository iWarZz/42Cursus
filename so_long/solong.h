/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:01:07 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/05 11:55:56 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "includes/libft/lift.h"

# define VOID '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTABLE 'C'
# define PLAYER 'P'

# define WIN_MESSAGE "YOU WIN !"

typedef struct s_point
{
	int x;
	int y;
}	t_point;



#endif