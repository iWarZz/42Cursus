/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:56:11 by ssalor            #+#    #+#             */
/*   Updated: 2023/02/14 15:15:47 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
//dans get next line
char		*get_next_line(int fd);
//static char	*ft_read(int fd, char *stash);
//static char	*ft_line(char **pstash, char stash);
//static char	*ft_stash(char *stash);

//dans get next line utils
void		*ft_calloc(size_t nbelem, size_t size);
int			ft_strlen(const char *a);
char		*ft_newline(char *str);
char		*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len);
void		ft_bzero(void *s, size_t n);

#endif