/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:19:39 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/21 11:20:56 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*void	ft_readfile(int fd, char *str)
{
	static char *buffer;
	int bytes;
	int i = 0;

	str = malloc(sizeof(BUFF_SIZE));
	bytes = read(fd, buffer, BUFF_SIZE);
	while (buffer[i] != '\n')
	{
		printf("%c", buffer[i]);
		i++;
	}
	buffer[i++] = '\0';
	free(str);
}*/

int		get_next_line(const int fd, char **line)
{
	 char buffer[BUFF_SIZE];
	static char *str;
	static int i;
	int bytes;
	int start;

	start = i;
	if ((line == NULL) || (fd < 0))
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE))))
		return (0);
	bytes = read(fd, buffer, BUFF_SIZE);
//	printf("buffer :\n%s\n", buffer);
//	str = ft_strcpy(*line, str);
	str = ft_strjoin(str, buffer);
	/*while (i < BUFF_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}*/
//	printf("strjoin :\n%s\n", str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_strsub(str, start, i - start);
		printf("line :\n%s\n", *line);
	}
	if (str[i] == '\0')
	{
		*line = ft_strdup(str);
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
	printf("--PREMIER APPEL--\n\n");
	get_next_line(fd, &line);
	printf("\n--DEUXIEME APPEL--\n\n");
	get_next_line(fd, &line);
	printf("\n--TROISIEME APPEL--\n\n");
	get_next_line(fd, &line);
	return (0);
}
