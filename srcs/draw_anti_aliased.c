/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anti_aliased.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:15:57 by khou              #+#    #+#             */
/*   Updated: 2019/02/15 00:46:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(float *a, float *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int		int_part(float nbr)
{
	return (floor(nbr));
}

float	frc_part(float nbr)
{
	return (ceil(nbr) - nbr);
}

float	rst_frc_part(float nbr)
{
	return (1 - frc_part(nbr));
}
void	draw_line(t_frame *frm, float x1, float y1, float x2, float y2)
{
	int steep;
	float	dx;
	float	dy;
	float	slope;
	
	steep = fabs(y1 - y2) > fabs(x1 - x2) ? 1 : 0;
	if (steep)
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
	}
	if (x2 < x1)
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0)
		slope = 1;
	else
		slope = dy / dx;	 
	if (steep)
	{
		while (x1 <= x2)
		{
			if (slope > 0)
			{
				fill_img(frm->data_img, int_part(y1), x1, rst_frc_part(y1));
				fill_img(frm->data_img, int_part(y1) + 1, x1, frc_part(y1));
			}
			else if (slope < 0)
			{
				fill_img(frm->data_img, int_part(y1), x1, rst_frc_part(y1));
				fill_img(frm->data_img, int_part(y1) - 1, x1, frc_part(y1));
			}
			else
				fill_img(frm->data_img, int_part(y1), x1, rst_frc_part(y1));
			y1 += slope;
			x1++;
		}
	}
	else
	{
		while (x1 <= x2)
		{
			if (slope > 0)
			{
				fill_img(frm->data_img, x1, int_part(y1), rst_frc_part(y1));
				fill_img(frm->data_img, x1, int_part(y1) + 1, frc_part(y1));
			}
			else if (slope < 0)
			{
				fill_img(frm->data_img, x1, int_part(y1), rst_frc_part(y1));
				fill_img(frm->data_img, x1, int_part(y1) - 1, frc_part(y1));
			}
			else
				fill_img(frm->data_img, x1, int_part(y1), rst_frc_part(y1));
			y1 += slope;
			x1++;
		}
	}
}

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
				draw_line(frm, frm->vct[i][j].x, frm->vct[i][j].y,
						frm->vct[i + 1][j].x, frm->vct[i + 1][j].y);
			if (j < frm->col - 1)
				draw_line(frm, frm->vct[i][j].x, frm->vct[i][j].y,
						frm->vct[i][j + 1].x, frm->vct[i][j + 1].y);
			j++;
		}
		i++;
	}
}
