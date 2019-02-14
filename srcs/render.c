/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:30 by khou              #+#    #+#             */
/*   Updated: 2019/02/13 18:21:11 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_frame *frm)
{
	scale(frm);//x,y,z
	rotate(frm);//x,y,x
	project(frm);//x,y
	recenter(frm);//x,y
/*
	int i = 0;
	int j;
	while (i < frm->row)
	{
		j= 0;
		while (j < frm->col)
		{
			printf("x: %f, y: %f, z: %f\n",
				   frm->vct[i][j].x, frm->vct[i][j].y, frm->vct[i][j].z);
			j++;
		}
		i++;
	}
*/
	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);	
}
