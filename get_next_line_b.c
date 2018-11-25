/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:16:49 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/25 11:12:20 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char *str;
	char buffer[BUFF_SIZE + 1];
	int ret;
	static int i;
	int start;
	char *tmp;

	start = i;
	if (i == -1)
	{
		free(str);
		return (0);
	}
	if (line == NULL || fd < 0)
		return (-1);
	if (!str)
		if (!(str = ft_strnew(1)))
			return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		tmp = str;
		buffer[ret] = '\0';
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(&str[i], '\n'))
			break ;
	}
	if (str)
	{
		if (ft_strchr(&str[i], '\n'))
		{
			while (str[i] && str[i] != '\n')
				i++;
			if (str[i] == '\n')
			{
				*line = ft_strsub(str, start, i - start);
				i++;
				return (1);
			}
		}
		else
		{
			*line = ft_strdup(&str[i]);
			i = -1;
			if (!strlen(*line))
				return (0);
			return (1);
		}
	}
	return (0);
}
