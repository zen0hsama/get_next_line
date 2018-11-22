/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:20:28 by ezonda            #+#    #+#             */
/*   Updated: 2018/11/22 11:18:57 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFF_SIZE 10000

int		get_next_line(const int fd, char **line);

#endif
