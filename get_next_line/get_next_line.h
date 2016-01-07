/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:48:01 by ndauteui          #+#    #+#             */
/*   Updated: 2015/12/09 11:35:16 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1200

int		ft_new_buff(char *buff, int j);
int		ft_create_line(char *buff, char **line, int j);
int		ft_buff_cpy(char *buff, char **line);
int		ft_get_line(char *buff, char **line);
int		get_next_line(int const fd, char **line);

#endif
