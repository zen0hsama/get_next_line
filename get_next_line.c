/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:42:14 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/23 16:28:33 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_verif(char **line, char **str, int fd)
{
	if (line == NULL || fd < 0)
		return (-1);
	if (!*str)
		if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	return (0);
}

int		ft_fill_line(char **line, char *str)
{
	static int	i;
	int			start;

	start = i;
	if (i == -1)
		return (0);
	if (!str)
		return (-1);
	if (ft_strchr(&str[i], '\n') != NULL)
	{
		while (str[i] != '\n' && str[i] != '\0')
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
		if (!ft_strlen(*line))
			return (0);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	int			line_ret;

	ret = 1;
	if (ft_verif(line, &str, fd) == -1)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
		if (ret == -1)
			return (-1);
	}
	line_ret = ft_fill_line(line, str);
	if (line_ret == 1)
		return (1);
	else if (line_ret == 0)
		return (0);
	else
		return (-1);
	return (0);
}
