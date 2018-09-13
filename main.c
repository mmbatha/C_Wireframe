/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:32:50 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/30 16:45:37 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int				ft_expose_hook(t_scope *scope)
{
	ft_redraw(scope);
	return (0);
}

static int				ft_display_key(void)
{
	ft_putendl("|******  Controls  ******|");
	ft_putendl("|***  Move on axes:  ****|");
	ft_putendl("|**  X - (LEFT, RIGHT)  *|");
	ft_putendl("|***  Y - (UP, DOWN)  ***|");
	ft_putendl("|************************|");
	ft_putendl("|*  Rotate (on Keypad): *|");
	ft_putendl("|****  X - 2 and 8  *****|");
	ft_putendl("|****  Y - 4 and 6  *****|");
	ft_putendl("|****  Z - 1 and 3  *****|");
	ft_putendl("|************************|");
	ft_putendl("|*  Zoom (on Keypad): ***|");
	ft_putendl("|******  IN - (+)  ******|");
	ft_putendl("|*****  OUT - (-)  ******|");
	ft_putendl("|************************|");
	ft_putendl("|***  RIGHT-CLICK or  ***|");
	ft_putendl("|*  PRESS [ESC] TO QUIT *|");
	ft_putendl("|************************|");
	return (0);
}

int						main(int argc, char **argv)
{
	t_scope		*scope;
	t_map		*map;

	if (argc == 2)
	{
		if (!(scope = (t_scope *)ft_memalloc(sizeof(t_scope))))
			ft_error_malloc();
		map = ft_parse(argv, 0);
		if (map->length == 0 || map->lines[0]->length == 0)
			ft_error_map();
		scope->map = map;
		ft_get_centre(scope);
		ft_create_windows("FDF", WINSIZE_W, WINSIZE_H, scope);
		ft_display_key();
		ft_change_map(scope);
		mlx_mouse_hook(scope->window, ft_mouse_hook, scope);
		mlx_expose_hook(scope->window, ft_expose_hook, scope);
		mlx_hook(scope->window, 2, 3, ft_keyhook, scope);
		mlx_loop(scope->mlx);
	}
	else
		ft_error_parse();
	return (0);
}
