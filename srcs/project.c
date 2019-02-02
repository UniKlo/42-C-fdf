/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 00:33:32 by khou              #+#    #+#             */
/*   Updated: 2019/02/01 18:24:55 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	pixel_size(int *pxl_size,t_dot *ai_pxl)
{
	int pxl_width = ai_pxl[0].x - ai_pxl[1].x;
	int	pxl_hight = ai_pxl[0].y - ai_pxl[1].y;

	printf("max_x: %d, min_x: %d, max_y: %d, min_y: %d\n",
		   ai_pxl[0].x, ai_pxl[1].x, ai_pxl[0].y, ai_pxl[1].y);
	*pxl_size = pxl_width * pxl_hight;
	printf("pxl_size: %d\n", *pxl_size);
}

void	pixel_measure(t_dot *ai_pxl, t_dot *pjt)
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

void	pjt_true_iso(t_dot *pjt, t_vct *org)//turn dots to pjt
{
	int iso_ang = 30;
	double radian_ang =	(iso_ang * M_PI) / 180;
//	printf("iso:%f\n", radian_ang);
	pjt->x = (org->x - org->y) * cos(radian_ang);
	pjt->y = (org->x + org->y) * sin(radian_ang) - org->z;
	pjt->z = 0;
}


void	project(t_frame *frm)
{
	int i = 0;
	int k = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			pjt_true_iso(&frm->dots[i][j], &frm->vct[k++]);
			j++;
//			pixel_measure(frm->ai_pxl, &frm->dots[i][j++]);
		}
		i++;
	}
//	pixel_size(&frm->pxl_size, frm->ai_pxl);
	
}
