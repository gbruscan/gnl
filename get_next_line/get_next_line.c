/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:38:26 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/09 11:35:25 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_buff(char *buff, int j)
{
	char		*tmp;
	int			size;

	size = ft_strlen((const char *)buff);
	tmp = (char *)malloc(sizeof(char) * (size - j));
	if (tmp == NULL)
		return (-1);
	ft_strcpy(tmp, (const char *)(buff + j + 1));
	ft_bzero(buff, size);
	ft_strcpy(buff, tmp);
	if (tmp)
		free(tmp);
	return (1);
}

int		ft_create_line(char *buff, char **line, int j)
{
	char		*tmp;
	char		*tmp2;

	tmp = *line;
	tmp2 = (char *)malloc(sizeof(char) * (j + ft_strlen(tmp) + 1));
	if (tmp2 == NULL)
		return (-1);
	ft_strcpy(tmp2, tmp);
	ft_strncat(tmp2, buff, j);
	*line = tmp2;
	if (tmp)
		free(tmp);
	return (ft_new_buff(buff, j));
}

int		ft_buff_cpy(char *buff, char **line)
{
	char	*tmp;
	char	*tp2;

	tmp = *line;
	tp2 = (char *)malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(tmp) + 1));
	if (tp2 == NULL)
		return (-1);
	ft_strcpy(tp2, tmp);
	ft_strcat(tp2, buff);
	*line = tp2;
	if (tmp)
		free(tmp);
	ft_bzero(buff, ft_strlen(buff));
	return (2);
}

int		ft_get_line(char *buff, char **line)
{
	int		j;

	j = 0;
	while (buff[j] != '\n' && buff[j] != 0)
		j++;
	if (buff[j] == 0)
		return (ft_buff_cpy(buff, line));
	else
		return (ft_create_line(buff, line, j));
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;
	int				status;

	if (line == NULL)
		return (-1);
	*line = ft_strdup("");
	status = 2;
	while (status == 2)
	{
		if (buff[0] == 0)
		{
			if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
				return (-1);
			if (ret > 0)
				buff[ret] = 0;
			if (ret == 0 && buff[0] != 0)
				return (ft_create_line(buff, line, 0));
			if (ret == 0)
				return (0);
		}
		status = ft_get_line(buff, line);
	}
	return (status);
}
