/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:43:14 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/27 07:14:31 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_get_colour(t_point *point1, t_point *point2)
{
	int		colour;
	int		z;

	if (point2->z_colour > point1->z_colour)
		z = point2->z_colour;
	else
		z = point1->z_colour;
	if (z < 0)
		colour = WHITE;
	else if (z >= 0 && z < 10)
		colour = RED;
	else if (z >= 10 && z < 20)
		colour = GOLD;
	else if (z >= 20 && z < 50)
		colour = GREY;
	else if (z >= 50 && z < 70)
		colour = BLUE;
	else if (z >= 80)
		colour = LIME;
	else
		colour = 0;
	return (colour);
}

void		ft_get_centre(t_scope *scope)
{
	t_point	pnt;
	int		x2;
	int		y2;

	pnt = scope->centre;
	y2 = scope->map->length;
	x2 = scope->map->lines[y2 - 1]->length;
	pnt.x_axis = (scope->map->lines[y2 - 1]->points[x2 - 1]->x_axis +
			scope->map->lines[0]->points[0]->x_axis) / 2;
	pnt.y_axis = (scope->map->lines[y2 - 1]->points[x2 - 1]->y_axis +
			scope->map->lines[0]->points[0]->y_axis) / 2;
	scope->centre = pnt;
}

void		ft_redraw(t_scope *scope)
{
	scope->image = mlx_new_image(scope->mlx, WINSIZE_W + 100, WINSIZE_H + 100);
	scope->pixel_image = mlx_get_data_addr(scope->image, \
			&(scope->bits_per_pixel), &(scope->size_line), &(scope->endian));
	ft_draw_map(scope);
	mlx_put_image_to_window(scope->mlx, scope->window, scope->image, -50, -50);
	mlx_destroy_image(scope->mlx, scope->image);
}

void		ft_change_map(t_scope *scope)
{
	int		width;
	int		height;
	double	size;

	width = (WINSIZE_W + 100) / 2;
	height = (WINSIZE_H + 100) / 2;
	scope->centre.x_axis == 0 ? scope->centre.x_axis = 10 : \
					scope->centre.x_axis;
	size = (width - 600) / (scope->centre.x_axis);
	ft_calc_translation(scope, -scope->centre.x_axis + width, \
			-scope->centre.y_axis + height, 0);
	ft_calc_scale(scope, size);
}

int			ft_single_point_out(t_point *point1)
{
	if (!(point1->x_axis > WINSIZE_W + 100 || point1->x_axis <= 0 \
				|| point1->y_axis > WINSIZE_H + 100 || point1->y_axis <= 0))
		return (1);
	else
		return (0);
}
