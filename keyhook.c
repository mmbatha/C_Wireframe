/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:42:37 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/10 12:06:56 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_keyhook_rotation(int keycode, t_scope *scope)
{
	if (keycode == KEY_ROT_X_UP)
		ft_calc_rotation(scope, ROTATE_X_UP, 'x');
	else if (keycode == KEY_ROT_X_DN)
		ft_calc_rotation(scope, ROTATE_X_DN, 'x');
	else if (keycode == KEY_ROT_Y_UP)
		ft_calc_rotation(scope, ROTATE_Y_UP, 'y');
	else if (keycode == KEY_ROT_Y_DN)
		ft_calc_rotation(scope, ROTATE_Y_DN, 'y');
	else if (keycode == KEY_ROT_Z_UP)
		ft_calc_rotation(scope, ROTATE_Z_UP, 'z');
	else if (keycode == KEY_ROT_Z_DN)
		ft_calc_rotation(scope, ROTATE_Z_DN, 'z');
}

static void		ft_keyhook_translation(int keycode, t_scope *scope)
{
	if (keycode == KEY_UP)
		ft_calc_translation(scope, 0, MVPIXEL_UP, 0);
	else if (keycode == KEY_DN)
		ft_calc_translation(scope, 0, MVPIXEL_DN, 0);
	else if (keycode == KEY_LT)
		ft_calc_translation(scope, MVPIXEL_LT, 0, 0);
	else if (keycode == KEY_RT)
		ft_calc_translation(scope, MVPIXEL_RT, 0, 0);
}

static void		ft_keyhook_scale(int keycode, t_scope *scope)
{
	if (keycode == KEY_ZOOM_IN)
		ft_calc_scale(scope, MVZOOM_IN);
	else if (keycode == KEY_ZOOM_OUT)
		ft_calc_scale(scope, MVZOOM_OUT);
}

int				ft_keyhook(int keycode, t_scope *scope)
{
	if (keycode == KEY_ESC)
	{
		ft_quit(scope);
	}
	ft_keyhook_rotation(keycode, scope);
	ft_keyhook_translation(keycode, scope);
	ft_keyhook_scale(keycode, scope);
	ft_redraw(scope);
	return (0);
}

void			ft_quit(t_scope *scope)
{
	int		i;
	t_map	*map;

	i = 0;
	mlx_destroy_window(scope->mlx, scope->window);
	map = scope->map;
	while (i < map->length)
	{
		ft_free2d(map->lines[i]->points, map->lines[i]->length);
		i++;
	}
	ft_freelines(map->lines, map->length);
	free(map);
	free(scope);
	exit(0);
}
