/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:16:49 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/26 00:55:30 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_readline(const int fd, char **str)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	if ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = ft_strdup(*str);
		ft_strdel(&(*str));
		*str = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	return (ret);
}

static void	ft_clearline(char **str, char *line_feed)
{
	char	*tmp;

	tmp = ft_strdup(line_feed + 1);
	ft_strdel(&(*str));
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*line_feed;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = ft_strnew(1)))
			return (-1);
	while (!(line_feed = ft_strchr(str[fd], '\n')))
	{
		if ((ret = ft_readline(fd, &str[fd])) < 0)
			return (-1);
		if (ret == 0 && !line_feed)
		{
			if (str[fd][0] == '\0')
				return (0);
			*line = ft_strdup(str[fd]);
			str[fd][0] = '\0';
			return (1);
		}
	}
	*line = ft_strsub(str[fd], 0, line_feed - str[fd]);
	ft_clearline(&str[fd], line_feed);
	return (1);
}
