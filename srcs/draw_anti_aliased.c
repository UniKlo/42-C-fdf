/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anti_aliased.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:15:57 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 02:10:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(double *a, double *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		int_part(double nbr)
{
	return (floor(nbr));
}

double	frc_part(double nbr)
{
	return (ceil(nbr) - nbr);
}

double	rst_frc_part(double nbr)
{
	return (1 - frc_part(nbr));
}

void	draw_line(t_frame *frm, t_vct p1, t_vct p2)
{
	int		steep;
	double	dx;
	double	dy;
	double	slope;

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
	slope = dx == 0 ? 1 : dy / dx;
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
