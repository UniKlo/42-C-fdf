/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:24:56 by khou              #+#    #+#             */
/*   Updated: 2019/02/08 20:25:32 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_vct *rot, double ang)
{
	int	y = rot->y;
	int	z = rot->z;
	rot->y = y * cos(ang) + z * sin(ang);
	rot->z = -y * sin(ang) + z * cos(ang);
}

void    y_rotation(t_vct *rot, double ang)
{
	int x = rot->x;
	int z = rot->z;
	rot->x = x * cos(ang) + z * sin(ang);
	rot->z = -x * sin(ang) + z * cos(ang);
}

void    z_rotation(t_vct *rot, double ang)
{
	int x = rot->x;
	int y = rot->y;
	rot->x = x * cos(ang) - y * sin(ang);
	rot->y = x * sin(ang) + y * cos(ang);
}

void	stage(t_frame *frm)
{
	int	ang = 0; //be able to change angel
	double radian_ang = (ang * M_PI) / 180;
	int i = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			x_rotation(&frm->vct[i][j], radian_ang);
			y_rotation(&frm->vct[i][j], radian_ang);
			z_rotation(&frm->vct[i][j], radian_ang);			
			j++;
		}
		i++;
	}
}
