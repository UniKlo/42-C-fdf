/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:20:33 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 00:09:27 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int     getnbr(char **line, int *nbr)
{
	while(**line)
	{
//		if (ft_isdigit(**line))
		if (**line != ' ' && **line != '\t')			
		{
			*nbr = atoi(*line);
//			printf("getnbr: %d, at %c ", *nbr, **line);
			if(*nbr < 0)
			{
				int tmp = 0;
				(*line)++;
				tmp = -*nbr;
				*line += ft_nbrlen(tmp);
			}
			else
//			printf("nbrlen: %d ", ft_nbrlen(*nbr));
				*line += ft_nbrlen(*nbr);
//			printf("move to: %c\n", **line);			
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
    char nbr[]="   0 2 45 -1     5 	0 ";
    int n = 0;

	tab = nbr;
	while (getnbr(&tab, &n))
        printf("%d\n", n);
    return (0);
}

*/
