/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:20:33 by khou              #+#    #+#             */
/*   Updated: 2018/11/29 15:48:03 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
//#include <stdio.h>

int     getnbr(char **line, int *nbr)
{
	while(**line)
	{
		if (ft_isdigit(**line))
		{
			*nbr = atoi(*line);
//			printf("I m here in getnbr: %d\n", *nbr);
			*line += ft_nbrlen(*nbr);
			return (1);
		}
		(*line)++;
	}
	return (0);
}


/*

#include <stdio.h>

int     main()
{
	char *tab;
    char nbr[]="   0 2 45 1 5      0 ";
    int n = 0;

	tab = nbr;
	while (getnbr(&tab, &n))
        printf("%d\n", n);
    return (0);
}
*/
