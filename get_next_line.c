/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:37:39 by gbruscan          #+#    #+#             */
/*   Updated: 2016/01/05 17:41:43 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int		ft_continue_buff(char *buff, char **line, int i, int fd)
{
	char	c;
	int		ret;
	int		j;

	j = 0;
	ret = 1;
	line[0] = ft_strdup(buff);
	while (ret > 0 && c != '\n')
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		while (buff && buff[j] != '\n' && buff[j] != '\0')
			j++;
		i += j;
		c = buff[j];
		buff = ft_strsub(buff, 0, j);
		line[0] = ft_strjoin(*line, buff);
	}
	if (c == '\n')
		return (1);
	return (0);
}

int		ft_get_new_line(char *buff, char **line, int fd)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff && buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
		return (ft_continue_buff(buff, line, i, fd));
	if (buff[i] == '\n')
	{
		line[0] = (char*)malloc(i + 1);
		while (j < i)
		{
			line[0][j] = buff[j];
			j++;
		}
		line[0][j] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int				ret;

	if (line == NULL)
		return (-1);
	read(fd, buff, BUFF_SIZE);
	return (ft_get_new_line(buff, line, fd));
	return (0);
}
