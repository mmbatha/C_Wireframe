/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:41:25 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/30 11:20:26 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** In rotation, we rotate the object at particular angle θ (theta) \
** from its origin.
*/

t_matrix		*ft_matrix_rotation_x(double axis)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	m->a1 = 1;
	m->b2 = cos(axis);
	m->b3 = -sin(axis);
	m->c2 = sin(axis);
	m->c3 = cos(axis);
	m->d4 = 1;
	return (m);
}

t_matrix		*ft_matrix_rotation_y(double axis)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	m->b2 = 1;
	m->a1 = cos(axis);
	m->c1 = -sin(axis);
	m->a3 = sin(axis);
	m->c3 = cos(axis);
	m->d4 = 1;
	return (m);
}

t_matrix		*ft_matrix_rotation_z(double axis)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	m->c3 = 1;
	m->a1 = cos(axis);
	m->a2 = -sin(axis);
	m->b1 = sin(axis);
	m->b2 = cos(axis);
	m->d4 = 1;
	return (m);
}

/*
**	A translation moves an object to a different position on the screen. \
**	You can translate a point in 2D by adding translation coordinate (t_x, t_y)\
**	to the original coordinate (X, Y) to get the new coordinate (X’, Y’).
*/

t_matrix		*ft_matrix_translation(double t_x, double t_y, double t_z)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	m->a4 = t_x;
	m->b4 = t_y;
	m->c4 = t_z;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

/*
** To change the size of an object, scaling transformation is used. \
** In the scaling process, you either expand or compress the dimensions \
** of the object. Scaling can be achieved by multiplying the original \
** coordinates of the object with the scaling factor to get the desired result.
*/

t_matrix		*ft_matrix_scale(double size)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		ft_error_malloc();
	m->a1 = size;
	m->b2 = size;
	m->c3 = size;
	m->d4 = 1;
	return (m);
}
