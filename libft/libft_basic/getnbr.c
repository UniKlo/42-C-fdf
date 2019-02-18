/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:20:33 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 02:05:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		getnbr(char **line, int *nbr)
{
	while (**line)
	{
		while (ft_isspace(**line) && **line)
			(*line)++;
		if (!**line)
			return (0);
		if (ft_isdigit(**line) || **line == '-')
		{
			*nbr = atoi(*line);
			if (*nbr < 0)
			{
				(*line)++;
				*line += ft_nbrlen(-*nbr);
			}
			else
				*line += ft_nbrlen(*nbr);
			return (1);
		}
		else
		{
			write(1, "Not vaild data\n", 15);
			exit(0);
		}
		(*line)++;
	}
	return (0);
}
