/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anti_aliased.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:15:57 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 03:15:52 by khou             ###   ########.fr       */
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

double	frc_part(double nbr)
{
	return (ceil(nbr) - nbr);
}

void	draw_w_slope(t_frame *frm, double x, double y)
{
	if (frm->slope >= 0)
	{
		fill_img(frm, floor(x), y, 1 - frc_part(y));
		fill_img(frm, floor(x) + 1, y, frc_part(y));
	}
	else if (frm->slope < 0)
	{
		fill_img(frm, floor(x), y, 1 - frc_part(y));
		fill_img(frm, floor(x) - 1, y, frc_part(y));
	}
}

void	draw_btw_dots(t_frame *frm, t_vct p1, t_vct p2)
{
	while (p1.x <= p2.x)
	{
		if (frm->steep)
			draw_w_slope(frm, p1.y, p1.x);
		else
			draw_w_slope(frm, p1.x, p1.y);
		p1.y += frm->slope;
		p1.x++;
	}
}

void	draw_line(t_frame *frm, t_vct p1, t_vct p2)
{
	double	dx;
	double	dy;

	frm->steep = fabs(p1.y - p2.y) > fabs(p1.x - p2.x) ? 1 : 0;
	if (frm->steep)
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
	frm->slope = dx == 0 ? 1 : dy / dx;
	draw_btw_dots(frm, p1, p2);
}
