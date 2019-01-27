/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:41:09 by khou              #+#    #+#             */
/*   Updated: 2019/01/26 02:54:28 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



/*
void	x_rotation(t_frame *frm)
{
	float	y;
	float	z;
	int i = 0;
	int		ang = 30;

	while (i < frm->dot_size)
	{
		y = frm->dots[i].y;
		z = frm->dots[i].z;
		frm->vct[i].y = y * cos(ang) + z * sin(ang);
		frm->vct[i].z = - y * sin(ang) + z * cos(ang);
		i++;
	}
}

void    y_rotation(t_frame *frm)
{
	float	x;
	float	z;
	int i = 0;
	int	ang = 30;
	while (i < frm->dot_size)
	{
		x =frm->dots[i].x;
		z =frm->dots[i].z;
		frm->vct[i].x = x * cos(ang) + z * sin(ang);
		frm->vct[i].z = -x * sin(ang) + z * cos(ang);
		i++;
	}
}
*/
void    z_rotation(t_vct *rot, t_dot *org, int ang)
{
	int x = org->x;
	int y = org->y;
	rot->x = x * cos(ang) - y * sin(ang);
	rot->y = x * sin(ang) + y * cos(ang);
	rot->z = org->z;
}

void	stage(t_frame *frm)
{
	frm->vct = malloc(sizeof (t_vct) * frm->dot_size);
	int	ang = 30; //be able to change angel
	int i = 0;
	int k = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
//			x_rotation(vct[k], frm->dots[i][j], ang);
//			y_rotation(vct[k], frm->dots[i][j], ang);
			z_rotation(&frm->vct[k], &frm->dots[i][j], ang);
			
			j++;
			k++;
		}
		i++;
	}
	project(frm, {);
}
