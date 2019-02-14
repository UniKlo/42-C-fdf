/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recenter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:27:42 by khou              #+#    #+#             */
/*   Updated: 2019/02/13 17:31:36 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recenter(t_frame *frm)
{
	int y0 = frm->row/2;
    int x0 = frm->col/2;
	frm->center[0].x = WIN_W/2 - frm->vct[y0][x0].x;
	frm->center[0].y = WIN_H/2 - frm->vct[y0][x0].y;
//	frm->center.z = 0.8;
	int i = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			frm->vct[i][j].x += frm->center[0].x + frm->center[1].x;
			frm->vct[i][j].y += frm->center[0].y + frm->center[1].y;
			j++;
		}
		i++;
	}
}
