/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:19:39 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/21 16:45:30 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_reader(int fd, char *str)
{
	char buffer[BUFF_SIZE];
	int reader;

	reader = read(fd, buffer, BUFF_SIZE);
	while (buffer[reader++] != '\n')
	{
		str = ft_strjoin(buffer, str);
		buffer[reader] = '\0';
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	static int i;
	int start;

	start = i;
	if ((line == NULL) || (fd < 0))
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = ft_reader(fd, str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_strsub(str, start, i - start);
	//	return (1);
	}
	printf("line :\n%s\n", *line);
	if (str[i] == '\0')
	{
		*line = ft_strdup(str);
	//	return (0);
	}
	i++;
	printf("i = %d\n", i);
	return (0);
}

int		main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;

	(void)ac;
	printf("--PREMIER APPEL--\n");
	get_next_line(fd, &line);
	printf("\n--DEUXIEME APPEL--\n");
	get_next_line(fd, &line);
	printf("\n--TROISIEME APPEL--\n");
	get_next_line(fd, &line);
/*	while (get_next_line(fd, &line) > 0)
		get_next_line(fd, &line);*/
	return (0);
}
