#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	readfile(int fd)
{
	static char *buffer;
	int bytes;
	static int i = 0;

	buffer = malloc(sizeof(BUFF_SIZE));
	bytes = read(fd, buffer, BUFF_SIZE);
	while (buffer[i] != '\n')
	{
		printf("%c", buffer[i]);
		i++;
	}
	buffer[i] = '\0';
	i++;
	free(buffer);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	readfile(open(av[1], O_RDONLY));
	putchar('\n');
	readfile(open(av[1], O_RDONLY));
	putchar('\n');
	readfile(open(av[1], O_RDONLY));
	putchar('\n');
	return (0);
}
