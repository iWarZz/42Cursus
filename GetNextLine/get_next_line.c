/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:54:41 by ssalor            #+#    #+#             */
/*   Updated: 2023/02/16 14:01:42 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char **pstash, char *stash)
{
	size_t	i;
	char	*new;
	char	*line;

	i = 0;
	new = ft_newline(stash);
	if (!new)
	{
		line = stash;
		*pstash = NULL;
		return (line);
	}
	line = malloc((new - stash + 2) * sizeof(char));
	if (!line)
	{
		*pstash = NULL;
		free(stash);
		return (NULL);
	}
	while (stash != new)
		line[i++] = *stash++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_line;
	char	*str;

	i = ft_strlen(stash);
	new_line = ft_newline(stash);
	j = i - (new_line - stash);
	if (j != 1)
	{
		str = malloc(j * sizeof(char));
	}
	else
		str = NULL;
	if (str)
	{
		while (j--)
			str[j] = new_line[j + 1];
	}
	free(stash);
	return (str);
}

static char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		byts;
	size_t	stash_len;

	if (ft_newline(stash))
		return (stash);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash_len = ft_strlen(stash);
	buffer[0] = '\0';
	while (!ft_newline(buffer))
	{
		byts = read(fd, buffer, BUFFER_SIZE);
		if (byts <= 0)
			break ;
		buffer[byts] = '\0';
		stash = ft_strjoin(stash, buffer, stash_len, byts);
		stash_len += byts;
		if (!stash)
			break ;
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(&stash, stash);
	if (stash != NULL)
		stash = ft_stash(stash);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s \n", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (1);
}
*/