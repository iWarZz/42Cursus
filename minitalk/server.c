/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:17:41 by ssalor            #+#    #+#             */
/*   Updated: 2023/03/21 15:30:17 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_mini_strjoin(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1 + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

char	*ft_new_buffer(char *buffer, char c)
{
	char	*tmp;

	tmp = ft_mini_strjoin(buffer, c);
	free(buffer);
	return (tmp);
}

void	ft_doit(int signal)
{
	static char	*buffer;
	static int	i = 7;
	static int	bit = 0;
	char		c;

	if (signal == SIGUSR1)
		bit |= 1 << i;
	i--;
	if (i == -1)
	{
		if (!buffer)
			buffer = ft_calloc(1, 1);
		c = (char)bit;
		if (c != '\0')
			buffer = ft_new_buffer(buffer, c);
		if (c == '\0')
		{
			ft_putstr_fd(buffer, 1);
			free(buffer);
			buffer = NULL;
		}
		i = 7;
		bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID : %s%d%s\n", GREEN, pid, END);
	while (1)
	{
		signal(SIGUSR1, ft_doit);
		signal(SIGUSR2, ft_doit);
		pause();
	}
	return (0);
}
