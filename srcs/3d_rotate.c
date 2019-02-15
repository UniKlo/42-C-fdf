/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:24:56 by khou              #+#    #+#             */
/*   Updated: 2019/02/14 18:12:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_vct *rot, double ang)
{
	float	y = rot->y;
	float	z = rot->z;
	rot->y = y * cos(ang) + z * sin(ang);
	rot->z = -y * sin(ang) + z * cos(ang);
}

void    y_rotation(t_vct *rot, double ang)
{
	float	x = rot->x;
	float	z = rot->z;
	rot->x = x * cos(ang) + z * sin(ang);
	rot->z = -x * sin(ang) + z * cos(ang);
}

void    z_rotation(t_vct *rot, double ang)
{
	float	x = rot->x;
	float	y = rot->y;
	rot->x = x * cos(ang) - y * sin(ang);
	rot->y = x * sin(ang) + y * cos(ang);
}

float	radian_ang(int angle)
{
	return ((angle * M_PI) / 180);
}

void	rotate(t_frame *frm)
{
	int i = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			x_rotation(&frm->vct[i][j], radian_ang(frm->ang.x));
			y_rotation(&frm->vct[i][j], radian_ang(frm->ang.y));
			z_rotation(&frm->vct[i][j], radian_ang(frm->ang.z));
			j++;
		}
		i++;
	}
}
