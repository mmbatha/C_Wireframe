/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:43:57 by mmbatha           #+#    #+#             */
/*   Updated: 2018/07/13 17:08:31 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strcat(char *str1, const char *str2)
{
	int	i;
	int	last_char;

	i = 0;
	while (str1[i] != '\0')
		i++;
	last_char = 0;
	while (str2[last_char] != '\0')
	{
		str1[i + last_char] = str2[last_char];
		last_char++;
	}
	str1[i + last_char] = '\0';
	return (str1);
}
