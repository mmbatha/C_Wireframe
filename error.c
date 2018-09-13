/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:40:50 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/06 17:14:02 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_exit(void)
{
	exit(1);
}

void			ft_error_malloc(void)
{
	ft_putendl_fd("There was a malloc error!", 2);
	ft_exit();
}

void			ft_error_map(void)
{
	ft_putendl_fd("There was a map error!", 2);
	ft_exit();
}

void			ft_error_parse(void)
{
	ft_putendl_fd("There was an error with the arguments passed!", 2);
	ft_exit();
}
