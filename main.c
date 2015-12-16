/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:13:52 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/16 14:55:12 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

int		main(void)
{
	int		fd;
	char	**line;
	char	buff[BUFF_SIZE +1];

	line = (char **)malloc(sizeof(char *) * 7);
	fd = open("test", O_RDONLY);
	get_next_line(fd, line);
	return (0);
}
