/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 00:33:32 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 02:45:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**pjt->z stores comparable value that how deep the dot is to Max/Min
*/

void	pjt_true_iso(t_frame *frm, t_vct *pjt)
{
	int		iso;
	double	x;
	double	y;
	double	z;

	iso = 30;
	x = pjt->x;
	y = pjt->y;
	z = pjt->z;
	pjt->x = (x - y) * cos(radian_ang(iso));
	pjt->y = (x + y) * sin(radian_ang(iso)) - z;
	pjt->z = fabs(z) / frm->ai_z.x;
}

void	project(t_frame *frm)
{
	int	i;
	int	j;

	i = 0;
	while (i < frm->row)
	{
		j = 0;
		while (j < frm->col)
		{
			pjt_true_iso(frm, &frm->vct[i][j]);
			j++;
		}
		i++;
	}
}
