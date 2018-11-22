/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:42:14 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/22 11:19:00 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	static int	i;
	char		buffer[BUFF_SIZE + 1];
	int			start;
		int			ret;

	start = i;
	if (line == NULL || fd < 0)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buffer, BUFF_SIZE);
	str[ret] = '\0';
	str = ft_strjoin(str, buffer);
	if (!str)
		return (0);
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
		else if (str[i] == '\0')
		{
			*line = ft_strdup(str);
			return (0);
		}
		else
			return (0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (ac == 2)
		close(fd);
}
