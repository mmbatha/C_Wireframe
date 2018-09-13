/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:47:40 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 16:58:29 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void			*ft_memset(void *b, int c, size_t len)
{
	size_t	co;
	char	*str;

	str = (char*)b;
	if (!str)
		return (NULL);
	if (len == 0)
		return (str);
	co = 0;
	while (co < len)
	{
		str[co] = (char)c;
		co++;
	}
	return (b);
}
