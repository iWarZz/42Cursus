/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:10:02 by ssalor            #+#    #+#             */
/*   Updated: 2023/04/26 11:22:16 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

void	panic(t_game *game, char *error_message)
{
	destroy(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
