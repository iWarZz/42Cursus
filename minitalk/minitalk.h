/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:29 by ssalor            #+#    #+#             */
/*   Updated: 2023/03/22 14:45:54 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/base/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

//Dans client:
void	ft_text(char *str, int pid);
void	ft_ctob(unsigned char c, int pid);
//Dans server:
void	ft_doit(int signal);
char	*ft_new_buffer(char *buffer, char c);
char	*ft_mini_strjoin(char *s, char c);
#endif