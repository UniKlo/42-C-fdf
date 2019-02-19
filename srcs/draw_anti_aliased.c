/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anti_aliased.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:15:57 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 23:24:53 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(float *a, float *b)
{
	int tmp;

	tmp = *a;
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

void	draw_line(t_frame *frm, t_vct p1, t_vct p2)
{
	int		steep;
	float	dx;
	float	dy;
	float	slope;

	steep = fabs(p1.y - p2.y) > fabs(p1.x - p2.x) ? 1 : 0;
	if (steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p2.x < p1.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0)
		slope = 1;
	else
		slope = dy / dx;
	while (p1.x <= p2.x)
	{
		if (steep)
		{
			if (slope >= 0)
			{
				fill_img(frm, int_part(p1.y), p1.x, rst_frc_part(p1.y));
				fill_img(frm, int_part(p1.y) + 1, p1.x, frc_part(p1.y));
			}
			else if (slope < 0)
			{
				fill_img(frm, int_part(p1.y), p1.x, rst_frc_part(p1.y));
				fill_img(frm, int_part(p1.y) - 1, p1.x, frc_part(p1.y));
			}
		}
		else
		{
			if (slope >= 0)
			{
				fill_img(frm, p1.x, int_part(p1.y), rst_frc_part(p1.y));
				fill_img(frm, p1.x, int_part(p1.y) + 1, frc_part(p1.y));
			}
			else if (slope < 0)
			{
				fill_img(frm, p1.x, int_part(p1.y), rst_frc_part(p1.y));
				fill_img(frm, p1.x, int_part(p1.y) - 1, frc_part(p1.y));
			}
		}
		p1.y += slope;
		p1.x++;
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
				draw_line(frm, frm->vct[i][j], frm->vct[i + 1][j]);
			if (j < frm->col - 1)
				draw_line(frm, frm->vct[i][j], frm->vct[i][j + 1]);
			j++;
		}
		i++;
	}
}
