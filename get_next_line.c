/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:37:39 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/15 19:52:56 by gbruscan         ###   ########.fr       */
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

char	*ft_line_filler(char *buff)
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

char	*ft_infinite_buffer(int fd, char *buff)
{
	int		ret;
	char	*chn;
	char	*tmp;
	
	ret = 1;
	tmp = ft_strdup(buff);	
	while (ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		tmp = ft_strjoin(tmp, buff);
	}
	tmp = ft_strsub(tmp, 0, ft_strlen(tmp));
	tmp = ft_line_filler(tmp);
	printf("%s\n", tmp);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	char			*buff2;
	int				ret;

	if (line == NULL)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	buff2 = ft_infinite_buffer(fd, buff);
	line[0] = ft_line_filler(buff);
//	printf("%s\n", line[0]);
	return (0);
}
