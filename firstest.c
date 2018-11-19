#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

void	readfile(int fd, int nline)
{
//	unsigned char buffer[15];
	unsigned char *buffer;
	int bytes;
	int i;
	int lines;

	i = 0;
	lines = 0;
	buffer = malloc(sizeof(char) * BUFF_SIZE + 1);
	bytes = read(fd, buffer, BUFF_SIZE);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			lines++;
			i++;
		}
		else
			i++;
	}
	printf("lines = %d\n", lines);
	i = 0;
	while (buffer[i])
	{
		while (buffer[i] != '\n')
		{
			printf("%c", buffer[i]);
			i++;
		}
		if (buffer[i] == '\n' && lines != nline)
		{
			printf("%c", buffer[i]);
			i++;
			nline++;
		}
		else
			buffer[i] = '\0';
	}
	buffer[i] = '\0';
	free(buffer);
}

int		main(int ac, char **av)
{
	(void)ac;
	int line = 1;
	while (av[1] != '\0' && line > 0)
	{
		readfile(open(av[1], O_RDONLY), line);
		line--;
	}
	return (0);
}
