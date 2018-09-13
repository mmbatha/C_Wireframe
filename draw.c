/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:40:36 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/26 15:47:49 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create_windows(char *title, int width, int height, \
		t_scope *scope)
{
	scope->mlx = mlx_init();
	scope->window = mlx_new_window(scope->mlx, width, height, title);
}

static void	ft_line_edges(t_point *pt1, t_point *pt2, double *tab)
{
	tab[0] = fabs(pt1->x_axis - pt2->x_axis);
	tab[1] = pt1->x_axis < pt2->x_axis ? 1 : -1;
	tab[2] = fabs(pt1->y_axis - pt2->y_axis);
	tab[3] = pt1->y_axis < pt2->y_axis ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void	ft_draw_point(t_point *point, t_scope *scope, int colour)
{
	int i;

	i = ((int)point->x_axis * 4) + ((int)point->y_axis * scope->size_line);
	scope->pixel_image[i] = colour;
	scope->pixel_image[++i] = colour >> 8;
	scope->pixel_image[++i] = colour >> 16;
}

static void	ft_draw_line(t_point pt1, t_point pt2, t_scope *scope)
{
	double	tab[6];
	int		state;

	ft_line_edges(&pt1, &pt2, tab);
	state = 1;
	while (state == 1 && !((int)pt1.x_axis == (int)pt2.x_axis && \
				(int)pt1.y_axis == pt2.y_axis))
	{
		if (ft_single_point_out(&pt1) == 1)
			ft_draw_point(&pt1, scope, ft_get_colour(&pt1, &pt2));
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)pt1.x_axis != (int)pt2.x_axis)
		{
			tab[4] -= tab[2];
			pt1.x_axis += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)pt1.y_axis != (int)pt2.y_axis)
		{
			tab[4] += tab[0];
			pt1.y_axis += tab[3];
			state = 1;
		}
	}
}

void		ft_draw_map(t_scope *scope)
{
	int		x;
	int		y;
	t_point	pt1;

	y = 0;
	while (y < scope->map->length)
	{
		x = 0;
		while (x < (scope->map->lines[y]->length))
		{
			pt1 = (*scope->map->lines[y]->points[x]);
			if (scope->map->lines[y]->points[x + 1])
				ft_draw_line(pt1, (*scope->map->lines[y]->points[x + 1]), \
						scope);
			if (scope->map->lines[y + 1])
				if (scope->map->lines[y + 1]->points[x] && \
						x <= scope->map->lines[y + 1]->length)
					ft_draw_line(pt1, (*scope->map->lines[y + 1]->points[x])\
							, scope);
			x++;
		}
		y++;
	}
}
