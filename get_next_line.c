/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:37:39 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/16 15:58:29 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int		ft_save_buff(char *buff, char **line)
{


}

int		ft_get_new_line(char *buff, char **line)
{
	int		i;

	i = 0;
	while (buff && buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n') //        ligne terminee
	{

	}
	else if (buff[i] == '\0') //   tout le buffer parcouru
	{


	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				ret;

	if (line == NULL)
		return (-1);
	read(fd, buff, BUFF_SIZE);
	ft_get_new_line(buff, line);
	return (0);
}
