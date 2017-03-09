/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:53:47 by fgallois          #+#    #+#             */
/*   Updated: 2017/03/09 12:17:15 by fgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static t_line *init_list(int fd)
{
	t_line *new;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	new->fd = fd;
	new->line = ft_strnew(0);
	new->next = NULL;
	return (new);
}

static char        *get_first_line(t_line *list, char **line)
{
	char    *text;
	int        i;

	i = 0;
	text = list->line;
	while (text[i])
	{
		if (text[i] == '\n')
		{
			*line = ft_strsub(text, 0, i);
			text = ft_strdup(text + (i + 1));
			return (text);
		}
		i++;
	}
	*line = ft_strdup(text);
	ft_strclr(text);
	ft_strclr(list->line);
	return (text);
}



static int		read_file(int fd, t_line *file)
{
	int ret;
	char buff[BUFF_SIZE + 1];

	while (!ft_strchr(file->line, '\n'))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) <= 0)
			return (0);
		buff[ret] = 0;
		if(!(file->line = ft_strjoin(file->line, buff)))
			return (-1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	return (1);
}


int		get_next_line(int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];
	static t_line *file;

	if (!file)
		file = init_list(fd);
	if (fd < 0 || !line || !file)
		return (-1);
		if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		file->line = ft_strjoin(file->line, buff);
	}
	else if (ret < 0)
		return (-1);
	else if (!ft_strlen(file->line))
		return (0);
	ret = read_file(fd, file);
	if (ret < 0)
		return (-1);
	file->line = get_first_line(file, line);
	//if (!ft_strlen(file->line) && !ft_strlen(*line) && !ret)
	//	return (0);
	return (1);
}
