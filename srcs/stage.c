/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:41:09 by khou              #+#    #+#             */
/*   Updated: 2019/01/30 13:13:22 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_vct *rot, t_dot *org, double ang)
{
	int	y = org->y;
	int	z = org->z;
	rot->x = org->x;
	rot->y = y * cos(ang) + z * sin(ang);
	rot->z = -y * sin(ang) + z * cos(ang);
}

void    y_rotation(t_vct *rot, t_dot *org, double ang)
{
	int x = org->x;
	int z = org->z;
	rot->x = x * cos(ang) + z * sin(ang);
	rot->y = org->y;
	rot->z = -x * sin(ang) + z * cos(ang);
}

void    z_rotation(t_vct *rot, t_dot *org, double ang)
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
	double radian_ang = (ang * M_PI) / 180;
	int i = 0;
	int k = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			x_rotation(&frm->vct[k], &frm->dots[i][j], radian_ang);
			y_rotation(&frm->vct[k], &frm->dots[i][j], radian_ang);
			z_rotation(&frm->vct[k], &frm->dots[i][j], radian_ang);			
			j++;
			k++;
		}
		i++;
	}
}
