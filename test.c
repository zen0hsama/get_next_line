/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:19:39 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/22 08:41:50 by ezonda           ###   ########.fr       */
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
	if (reader > 0)
	{
		str = ft_strjoin(str, buffer);
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
//	if (*str)
//		ft_strcpy(*line, str);
	str = ft_reader(fd, str);
	if (*str)
	{
		while (str[i] != EOF && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			*line = ft_strsub(str, start, i - start);
		//		return (1);
		}
		if (str[i] == '\0')
		{
			*line = ft_strdup(str);
		//		return (1);
		}
			i++;
		printf("i = %d\n", i);
		return (1);
	}
	return (0);
}

/*int		main(int argc, char **argv)
{
	int fd;
	char*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}*/
