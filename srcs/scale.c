/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:36:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 02:28:42 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deepth_ai(t_vct *ai_z, double z)
{
	if (z >= 0 && z > ai_z->x)
		ai_z->x = z;
	if (z < 0 && z < ai_z->y)
		ai_z->y = z;
}

/*
** deepth is frm->center[0].z;
*/

void	apply_scale(t_frame *frm)
{
	int			i;
	int			j;
	static int	first;

	first = 1;
	i = 0;
	if (first)
		frm->vct = malloc(sizeof(t_vct *) * frm->row);
	while (i < frm->row)
	{
		if (first)
			frm->vct[i] = malloc(sizeof(t_vct) * frm->col);
		j = 0;
		while (j < frm->col)
		{
			deepth_ai(&frm->ai_z, frm->org[i][j].z);
			frm->vct[i][j].x = frm->org[i][j].x * frm->scale;
			frm->vct[i][j].y = frm->org[i][j].y * frm->scale;
			frm->vct[i][j].z = frm->org[i][j].z * frm->scale * frm->center[0].z;
			frm->vct[i][j].c = frm->org[i][j].c;
			j++;
		}
		i++;
	}
	first = 0;
}

void	scale(t_frame *frm)
{
	int unit_row;
	int	unit_col;
	int scale;

	unit_row = WIN_H * 0.6 / (frm->row);
	unit_col = WIN_W * 0.6 / (frm->col);
	scale = unit_row <= unit_col ? unit_row : unit_col;
	frm->scale = scale + frm->center[1].z;
	apply_scale(frm);
}
