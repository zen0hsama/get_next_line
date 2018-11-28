/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:00:55 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/17 17:42:04 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1) || (!(s2)))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
