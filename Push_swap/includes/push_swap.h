/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:50:59 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/29 14:55:24 by ssalor           ###   ########.fr       */
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
	int				value;
	int				index;
	int				chunk;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//dans main.c
int		main(int argc, char **argv);
void	print_stack(t_node *stack);

//dans check.c
void	check_syntax(char *str);
void	check_rep(t_node *a, int value);

//dans utils.c
void	create_stack(t_node **a, char **arg_values);
void	listadd_top(t_node **stack, int value, int index, int chunk_nbr);
void	listadd_bottom(t_node **stack, int value, int index, int chunk_nbr);
t_node	*get_last_node(t_node *stack);
void	set_index(t_node *stack);

//dans utils_2.c
void	listdel_bottom(t_node **stack);
void	listdel_top(t_node **stack);

//dans swap.c
void	ps_swap(t_node *stack);
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);

//dans push.c
void	ps_push(t_node **stack_src, t_node **stack_dest);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

//dans rotate.c
void	ps_rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

//dans reverse_rotate.c
void	ps_reverse_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif