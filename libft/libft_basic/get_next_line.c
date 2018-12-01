/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:53:01 by khou              #+#    #+#             */
/*   Updated: 2018/08/09 16:09:47 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		get_begin(char **str, char **line, char *p_nl)
{
	char	*beg;

	if ((*str)[0] == '\0')
		return (0);
	if (p_nl && !(*p_nl = '\0'))
	{
		*line = *str;
		beg = ft_strdup(p_nl + 1);
		*str = beg;
	}
	else
	{
		*line = ft_strdup(*str);
		ft_memdel((void **)str);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	static char	*str[MAX_FD];
	char		*tmp;
	char		*p_nl;

	if (fd < 0 || read(fd, buffer, 0) < 0 || !line || fd > MAX_FD)
		return (-1);
	(!str[fd]) && (str[fd] = ft_strnew(0));
	while (!(p_nl = ft_strchr(str[fd], '\n')) &&
			(ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buffer);
		free(tmp);
	}
	return (get_begin(&str[fd], line, p_nl));
}
