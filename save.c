/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:22:59 by gbruscan          #+#    #+#             */
/*   Updated: 2015/12/16 14:23:14 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_line_filler(char *buff)
{
    int     i;
    int     j;
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

char    *ft_infinite_buffer(int fd, char *buff)
{
    int         ret;
    char        *tmp;

    tmp = ft_strdup(buff);
    while (ret != 0)
    {
        ret = read(fd, buff, BUFF_SIZE);
        if (ret < BUFF_SIZE)
            buff = ft_strsub(buff, 0, ret);
        tmp = ft_strjoin(tmp, buff);
    }
    tmp = ft_line_filler(tmp);
    return (tmp);
}
