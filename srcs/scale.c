/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:36:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/16 01:27:08 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_scale(t_frame *frm)
{
	int		i;
	int		j;
	float	deepth;

	i = 0;
	deepth = frm->center[0].z;
	frm->vct = malloc(sizeof(t_vct *) * frm->row);
	while (i < frm->row)
	{
		frm->vct[i] = malloc(sizeof(t_vct) * frm->col);
		j = 0;
		while (j < frm->col)
		{
			frm->vct[i][j].x = frm->org[i][j].x * frm->scale;
			frm->vct[i][j].y = frm->org[i][j].y * frm->scale;
			frm->vct[i][j].z = frm->org[i][j].z * frm->scale * deepth;
			j++;
		}
		i++;
	}
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
