/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:42:17 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/21 14:29:20 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_calc_matrix(t_point *point1, t_matrix *m, t_scope *scope)
{
	double temp_x;
	double temp_y;
	double temp_z;

	point1->x_axis -= scope->centre.x_axis;
	point1->y_axis -= scope->centre.y_axis;
	temp_x = point1->x_axis * m->a1 + point1->y_axis * m->a2 + \
			point1->z_axis * m->a3 + point1->size * m->a4;
	temp_y = point1->x_axis * m->b1 + point1->y_axis * m->b2 + \
			point1->z_axis * m->b3 + point1->size * m->b4;
	temp_z = point1->x_axis * m->c1 + point1->y_axis * m->c2 + \
			point1->z_axis * m->c3 + point1->size * m->c4;
	point1->x_axis = temp_x;
	point1->y_axis = temp_y;
	point1->z_axis = temp_z;
	point1->x_axis += scope->centre.x_axis;
	point1->y_axis += scope->centre.y_axis;
}

static void		ft_calc_matrices(t_matrix *m, t_scope *scope)
{
	int x;
	int y;

	y = 0;
	while (y < scope->map->length)
	{
		x = 0;
		while (x < (scope->map->lines[y]->length))
		{
			ft_calc_matrix(scope->map->lines[y]->points[x], m, scope);
			x++;
		}
		y++;
	}
}

void			ft_calc_rotation(t_scope *scope, double rotation, char axis)
{
	t_matrix *m_rotation;

	if (axis == 'x')
		m_rotation = ft_matrix_rotation_x(rotation);
	else if (axis == 'y')
		m_rotation = ft_matrix_rotation_y(rotation);
	else
		m_rotation = ft_matrix_rotation_z(rotation);
	ft_calc_matrices(m_rotation, scope);
	free(m_rotation);
}

void			ft_calc_translation(t_scope *scope, double x, double y, \
		double z)
{
	t_matrix *m_translation;

	m_translation = ft_matrix_translation(x, y, z);
	ft_calc_matrices(m_translation, scope);
	ft_get_centre(scope);
	free(m_translation);
}

void			ft_calc_scale(t_scope *scope, double size)
{
	t_matrix *m_transform;

	m_transform = ft_matrix_scale(size);
	ft_calc_matrices(m_transform, scope);
	free(m_transform);
}
