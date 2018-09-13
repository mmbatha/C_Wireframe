/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:13:25 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 17:18:48 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char			*ft_strdup(const char *str1)
{
	unsigned int	i;
	size_t			length;
	char			*str2;

	i = 0;
	length = ft_strlen(str1);
	str2 = ft_memalloc(sizeof(*str2) * (length + 1));
	if (str2 == NULL)
		return (NULL);
	while (i < length)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
