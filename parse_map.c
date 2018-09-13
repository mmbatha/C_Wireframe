/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:40:18 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/10 12:14:11 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_getnbr(char *str)
{
	int num;
	int negative;

	negative = 1;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (negative * num);
}

void		ft_freestr(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int			ft_points(char *line, int break_line, t_point ***points)
{
	char	**str;
	int		i;

	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i] != 0)
		i++;
	*points = ft_memalloc(sizeof(t_point) * i);
	if (!*points)
		ft_error_malloc();
	i = 0;
	while (str[i] != 0)
	{
		(*points)[i] = ft_memalloc(sizeof(t_point));
		if (!(*points)[i])
			ft_error_malloc();
		(*points)[i]->x_axis = i * SIZE_WIDTH;
		(*points)[i]->y_axis = break_line * SIZE_HEIGHT;
		(*points)[i]->z_axis = ft_getnbr(str[i]);
		(*points)[i]->size = 1;
		(*points)[i]->z_colour = (*points)[i]->z_axis;
		i++;
	}
	ft_freestr(str);
	return (i);
}

int			ft_map_line(char *map)
{
	int		fd;
	int		break_lines;
	char	buffer;

	fd = 0;
	break_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		ft_error_map();
	while (read(fd, &buffer, 1))
	{
		if (buffer == 10)
			break_lines++;
	}
	close(fd);
	return (break_lines);
}

t_map		*ft_parse(char **argv, int fd)
{
	char		*line;
	int			break_line;
	t_map		*map;
	t_line		*line_to_map;
	t_point		**points;

	break_line = 0;
	if (!(map = ft_memalloc(sizeof(t_map))) || \
			!(map->lines = ft_memalloc(sizeof(t_line) * ft_map_line(argv[1]))))
		ft_error_malloc();
	map->length = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(line_to_map = ft_memalloc(sizeof(t_line))))
				ft_error_malloc();
			line_to_map->length = ft_points(line, break_line, &points);
			line_to_map->points = points;
			map->lines[break_line++] = line_to_map;
			free(line);
		}
		map->length = break_line;
	}
	return (map);
}
