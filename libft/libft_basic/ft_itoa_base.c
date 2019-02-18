/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:56:58 by khou              #+#    #+#             */
/*   Updated: 2019/02/17 17:57:42 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char    *ft_itoa_base(int nbr, int base)
{
	char	*str = malloc(sizeof(char) * 4000);
	char	*nbr_base = "0123456789ABCDEF";

	if (!str)
		return (NULL);
	if (nbr == 0)
		return ("0");
	if (nbr == -2147483648 && base == 10 )
		return ("-2147483648");

	int end = 0;
	if (nbr < 0)
	{
		if (base == 10)
		{
			str[0] = '-';
			end++;
		}
		nbr = -nbr;
	}
	end += ft_nbrlen_base(nbr, base);
	str[end] = '\0';
	end--;
	while (nbr)
	{
		str[end--] = nbr_base[nbr % base];
		nbr /= base;
	}
	return(str);
}