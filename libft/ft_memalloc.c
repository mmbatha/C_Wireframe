/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:11:20 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/30 11:27:20 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void			*ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = (void*)malloc(size)) && size)
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	else
		free(mem);
	return (NULL);
}
