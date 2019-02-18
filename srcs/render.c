/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:30 by khou              #+#    #+#             */
/*   Updated: 2019/02/16 19:42:20 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instruction(t_frame *m)
{
	mlx_string_put(m->mlx, m->win, 0, 0, 0x00c3d1, "Instructions: ");
	mlx_string_put(m->mlx, m->win, 0, 20, 0x01858e, "Zoom in/out: mouse wheel");
	mlx_string_put(m->mlx, m->win, 0, 40, 0x01858e,
				"Reposition: key <up down left right> arrows");
	mlx_string_put(m->mlx, m->win, 0, 60, 0x01858e,
				"Change altitude: key <+ ->");
	mlx_string_put(m->mlx, m->win, 0, 80, 0x01858e, "Rotate x: key <W S>");
	mlx_string_put(m->mlx, m->win, 0, 100, 0x01858e, "Rotate y: key <A D>");
	mlx_string_put(m->mlx, m->win, 0, 120, 0x01858e, "Rotate z: key <Q E>");
	mlx_string_put(m->mlx, m->win, 0, 140, 0x01858e, "Reset: key <R>");
	mlx_string_put(m->mlx, m->win, 0, 160, 0x01858e,
				"Exit: click reb button / key <ESC>");

}

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
	printf("maz_z: %f, min_z: %f\n", frm->ai_z.x, frm->ai_z.y);
	project(frm);//x,y
	recenter(frm);//x,y
	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);
	instruction(frm);
	return (0);
}
