/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:56:25 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/10 12:29:54 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "includes/libft.h"

static char		*ft_strjoinf(char *s1, char *s2)
{
	char *ret;

	if (!(ret = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	free((char *)s1);
	return (ret);
}

static int		ft_read_line(int fd, char **buffer, char **line, char *pos)
{
	int result;

	*line = ft_strdup(*buffer);
	while (!pos)
	{
		if ((result = read(fd, *buffer, BUFF_SIZE)) < 0)
			return (-1);
		if ((pos = ft_strchr(*buffer, '\n')) == NULL && !result)
			return ((*buffer)[0] = 0);
		else if (pos)
		{
			(*buffer)[result] = result ? 0 : (*buffer)[result];
			pos[0] = 0;
			*line = ft_strjoinf(*line, *buffer);
			ft_strcpy(*buffer, pos + 1);
		}
		else
		{
			(*buffer)[result] = result ? 0 : (*buffer)[result];
			*line = ft_strjoinf(*line, *buffer);
			(*buffer)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer;
	char		*pos;
	int			result;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!buffer && !(buffer = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((pos = ft_strchr(buffer, '\n')))
	{
		*pos = 0;
		*line = ft_strdup(buffer);
		ft_strcpy(buffer, pos + 1);
		return (*line ? 1 : -1);
	}
	else
		result = ft_read_line(fd, &buffer, line, NULL);
	if (result == 0 && ft_strlen(*line) == 0)
	{
		free(buffer);
		free(*line);
	}
	if (result == -1)
		return (-1);
	return (result ? 1 : ft_strlen(*line) != 0);
}
