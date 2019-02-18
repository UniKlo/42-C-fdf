/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:27:59 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 01:08:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	valid_char(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int nbr;
	int sign;

	nbr = 0;
	sign = 0;
	if (str[0] == '-')
	{
		sign = -1;
		++str;
	}
	while (*str && valid_char(*str))
	{
		nbr *= str_base;
		*str >= '0' && *str <= '9' ? nbr += *str - '0' : 0;
		*str >= 'a' && *str <= 'f' ? nbr += *str - 'a' + 10 : 0;
		*str >= 'A' && *str <= 'F' ? nbr += *str - 'A' + 10 : 0;
		str++;
	}
	return (sign ? nbr = sign * nbr : nbr);	
}
