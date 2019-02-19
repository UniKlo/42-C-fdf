/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:30 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 15:39:43 by khou             ###   ########.fr       */
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

/*
**to right and to down
*/

void	draw_img(t_frame *frm)
{
	int	i;
	int	j;

	i = 0;
	while (i < frm->row)
	{
		j = 0;
		while (j < frm->col)
		{
			if (i < frm->row - 1)
				draw_line(frm, frm->vct[i][j], frm->vct[i + 1][j]);
			if (j < frm->col - 1)
				draw_line(frm, frm->vct[i][j], frm->vct[i][j + 1]);
			j++;
		}
		i++;
	}
}

int		render(t_frame *frm)
{
	clear_img(frm);
	scale(frm);
	rotate(frm);
	project(frm);
	recenter(frm);
	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);
	instruction(frm);
	return (0);
}
