/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:42:14 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/22 16:57:23 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	static int	i;
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	int			start;

	start = i;
	ret = 1;
	if (line == NULL || fd < 0)
		return (-1);
	if (!str)
		if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
		if (ret == -1)
			return (-1);
	}
	if (!str)
		return (-1);
	else
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, start, i - start);
			i++;
			return (1);
		}
		else
		{
			*line = ft_strdup(str);
			return (0);
		}
	}
	return (0);
}
