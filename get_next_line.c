/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:37:39 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/15 18:49:56 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "../Projects_C/libft/libft.h"

int		ft_strlen_without_n(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			j += 1;
		i++;
	}
	return (i - j);
}

char	*ft_line_filler(char *buff, char **line)
{
	int     i;
	int		j;
	char    *chn;
	
	i = 0;
	while (buff[i++] != '\0')
	{
		if (buff[i] == '\n')
			i += 1;
	}
	chn = (char *)malloc(sizeof(char) * i + 1);
	if (!chn)
		return (NULL);
	i = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			i += 1;
		chn[j++] = buff[i++];
	}
	chn[j] = '\0';
	return (chn);
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;

	if (line == NULL)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	printf("ret = %d\n", ret);
	line[0] = ft_line_filler(buff, line);
//	printf("%s\n", line[0]);
	return (0);
}
