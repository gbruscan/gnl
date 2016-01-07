/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:13:52 by gbruscan          #+#    #+#             */
/*   Updated: 2016/01/07 11:04:27 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

int		main(void)
{
	int		fd;
	char	**line;

	line = (char **)malloc(sizeof(char *) * 2);
	if (line == NULL)
		printf("tamere");
	fd = open("text", O_RDONLY);
	get_next_line(fd, line);
	get_next_line(fd, line);
	close(fd);
	printf("%s", line[0]);
	return (0);
}
