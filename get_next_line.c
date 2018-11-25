/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 08:53:07 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/25 12:31:27 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int		ft_check(int fd, char **line)
{
	if (line == NULL || fd < 0)
		return (-1);
	return (0);
}

int		ft_fill_line(char *str, char **line)
{
	static int i;
	int start;

	start = i;
	if (i == -1)
		return (0);
	if (!str)
		return (-1);
//	printf("2\n");
//	getchar();
	if (str)
	{
		if (ft_strchr(&str[i], '\n'))
		{
			while (str[i] && str[i] != '\n')
				i++;
			if (str[i] == '\n')
			{
//				printf("3\n");
//				getchar();
				*line = ft_strsub(str, start, i - start);
				i++;
				return (1);
			}
		}
		else
		{
//			printf("4\n");
//			getchar();
			*line = ft_strdup(&str[i]);
			i = -1;
			if (!ft_strlen(*line))
				return (0);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *str;
	char buffer[BUFF_SIZE + 1];
	char *tmp;
	int ret;

//	printf("start\n");
//	getchar();
	if (ft_check(fd, line) == -1)
		return(-1);
	if (!str)
		if (!(str = ft_strnew(1)))
			return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		tmp = ft_strjoin(str,buffer);
		free(str);
		str = tmp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
//	printf("1\n");
//	getchar();
	return (ft_fill_line(str, line));
}
