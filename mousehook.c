/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:42:37 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/10 12:04:15 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_mouse_hook(int button, int x, int y, t_scope *scope)
{
	if (button == 2 && x > 0 && y > 0 && scope)
		ft_quit(scope);
	return (0);
}

void			ft_free2d(t_point **points, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void			ft_freelines(t_line **lines, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
