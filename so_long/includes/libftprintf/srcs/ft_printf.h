/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:59:54 by ssalor            #+#    #+#             */
/*   Updated: 2023/01/18 15:20:44 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

/*dans printf*/
int		ft_printf(const char *nom, ...);
int		ft_search_format(va_list oui, const char format);
int		ft_printchar(int c);
/*dans printf_tools*/
int		ft_printstr(char *str);
void	ft_putstr(char *str);
int		ft_printnbr(int n);
/*dans printf_ptr*/
int		ft_print_ptr(unsigned long long ptr);
void	ft_put_ptr(unsigned long long num);
int		ft_ptr_len(unsigned long long num);
/*dans printf_tools2*/
int		ft_print_unsigned(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_num_len(unsigned	int num);
/*dans print_hexa*/
int		ft_print_hexa(unsigned int num, const char format);
void	ft_put_hexa(unsigned int num, const char format);
int		ft_hexa_len(unsigned int num);

#endif
