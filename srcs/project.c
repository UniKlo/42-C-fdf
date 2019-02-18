/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 00:33:32 by khou              #+#    #+#             */
/*   Updated: 2019/02/16 22:47:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	pixel_size(int *pxl_size,t_vct *ai_pxl)
{
	int pxl_width = ai_pxl[0].x - ai_pxl[1].x;
	int	pxl_hight = ai_pxl[0].y - ai_pxl[1].y;

	printf("max_x: %d, min_x: %d, max_y: %d, min_y: %d\n",
		   ai_pxl[0].x, ai_pxl[1].x, ai_pxl[0].y, ai_pxl[1].y);
	*pxl_size = pxl_width * pxl_hight;
	printf("pxl_size: %d\n", *pxl_size);
}

void	pixel_measure(t_vct *ai_pxl, t_vct *pjt)
{
	
	if (pjt->x >= 0 && pjt->x > ai_pxl[0].x)
		ai_pxl[0].x = pjt->x;
	if (pjt->x < 0 && pjt->x < ai_pxl[1].x)
		ai_pxl[1].x = pjt->x;
	if (pjt->y >= 0 && pjt->y > ai_pxl[0].y)
		ai_pxl[0].y = pjt->y;
	if (pjt->y < 0 && pjt->y < ai_pxl[1].y)
		ai_pxl[1].y = pjt->y;
}
*/

void	pjt_true_iso(t_frame *frm, t_vct *pjt)//turn vct to pjt
{
	int iso = 30;
	float	x;
	float	y;
	float	z;
	x = pjt->x;
	y = pjt->y;
	z = pjt->z;
	pjt->x = (x - y) * cos(radian_ang(iso));
	pjt->y = (x + y) * sin(radian_ang(iso)) - z;
	pjt->z = fabs(z) / frm->ai_z.x;//how deep cmp to Max
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
