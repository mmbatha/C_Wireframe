/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:03:16 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 17:49:32 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static size_t			ft_len_ctr_stop(const char *str, int start, \
		char ctr_stop)
{
	size_t	ctr;

	if (!str)
		return (0);
	ctr = 0;
	while (str[start] && (str[start] != ctr_stop))
	{
		start++;
		ctr++;
	}
	return (ctr);
}

static int				ft_split_c(char *str, char c)
{
	int		cnt_word;
	int		ctr;

	ctr = 0;
	cnt_word = 0;
	while (str[ctr])
	{
		while (str[ctr] && str[ctr] != c)
			ctr++;
		while (str[ctr] && str[ctr] == c)
			ctr++;
		cnt_word++;
	}
	return (cnt_word);
}

char					**ft_strsplit(char const *s, char c)
{
	int				cnt_word;
	int				i;
	unsigned int	ctr;
	char			**array_s;
	char			*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	ctr = 0;
	cnt_word = ft_split_c(str, c);
	array_s = (char**)ft_memalloc(sizeof(char*) * (cnt_word + 1));
	ctr = 0;
	i = 0;
	while (i < cnt_word)
	{
		while ((str[ctr] == (char)c) && str[ctr])
			ctr++;
		array_s[i] = ft_strsub(str, ctr, ft_len_ctr_stop(str, ctr, c));
		while ((str[ctr] != (char)c) && str[ctr])
			ctr++;
		i++;
	}
	array_s[i] = 0;
	return (array_s);
}
