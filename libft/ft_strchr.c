/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:06:49 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 17:13:24 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strchr(const char *str, int firstc)
{
	char *s;

	s = (char*)str;
	if (s)
	{
		while (*s)
		{
			if ((char)firstc == *s)
				return (s);
			s++;
		}
		if ((char)firstc == 0)
			return (s);
	}
	return (NULL);
}
