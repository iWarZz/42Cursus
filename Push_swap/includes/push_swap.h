/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:50:59 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/23 14:06:32 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>

# include "libftprintf/libft/libft.h"
# include "libftprintf/srcs/ft_printf.h"

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

# define NO_ARG "Error: No argument."
# define ER_SYNT "Error: Syntax error in argument."
# define ARG_NOT_INT "Error: Argument does not fit into an int."
# define ARG_REP "Error: Repetition in arguments."
# define MAL_ER "Malloc failed"
//dans main.c
int		main(int argc, char **argv);

//dans check.c
void	create_stack(t_node **a, char **arg_values);
void	check_syntax(char *str);

//dans utils.c
void	check_rep(t_node *a, int value);
void	listadd_bottom(t_node **a, int value);
t_node	*get_last_node(t_node *stack);
void	rotary_please(t_node **a);

//dans swap.c

# endif