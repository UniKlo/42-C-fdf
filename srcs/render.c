/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:30 by khou              #+#    #+#             */
/*   Updated: 2019/02/15 16:53:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_frame *frm)
{
	int i;

	i = 0;
	while (i < WIN_W * WIN_H * 4)
		frm->data_img[i++] = 0;
}

int		render(t_frame *frm)
{
	clear_img(frm);
	scale(frm);//x,y,z
	rotate(frm);//x,y,x
	project(frm);//x,y
	recenter(frm);//x,y
	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);
	return (0);
}
