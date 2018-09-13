/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:49:53 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 17:57:44 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*new_str;
	unsigned int	ctr;

	if (!(new_str = ft_strnew(len)) || !s)
		return (NULL);
	str = (char *)s;
	ctr = 0;
	while (ctr < len)
	{
		new_str[ctr] = str[start];
		start++;
		ctr++;
	}
	return (new_str);
}
