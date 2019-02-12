/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:36:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/12 14:24:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_scale(t_frame *frm)
{
	int i;
	int j;
	float deepth;
	
	i = 0;
	deepth = frm->center[1].z;
	while (i < frm->row)
	{
		j = 0;
		while (j < frm->col)
		{
			frm->vct[i][j].x = j * frm->scale;
			frm->vct[i][j].y = i * frm->scale;
			frm->vct[i][j].z = frm->vct[i][j].z * frm->scale * 0.2 + deepth;
			j++;
		}
		i++;
	}
}

void	scale(t_frame *frm)
{
	int unit_row = WIN_H*0.6/(frm->row);
	int	unit_col = WIN_W*0.6/(frm->col);
	frm->scale = unit_row <= unit_col ? unit_row : unit_col;
	printf("scale: %d, deepth: %f\n", frm->scale, frm->center[1].z);
	apply_scale(frm);
}
