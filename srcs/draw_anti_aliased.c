

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
void	draw_line(t_frame *frm, float x1, float y1, float x2, float y2)//change them all to float. projection points could be float.
{
	int steep = fabs(y1 - y2) > fabs(x1 - x2) ? 1 : 0;
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
	float	dx = x2 - x1;
	float	dy = y2 - y1;
	float	slope;
	if (dx == 0)
		slope = 1;
	slope = dy / dx;

	int		xpxl1 = x1;
	int		xpxl2 = x2;
	float	y = y1;

	int		x = xpxl1;
	 
	if (steep)
	{
		while (x <= xpxl2)
		{
			if (slope > 0)
			{
				fill_img(frm->data_img, int_part(y), x, rst_frc_part(y));
				fill_img(frm->data_img, int_part(y) +1, x, frc_part(y));
			}
			else if (slope <= 0)
			{
				fill_img(frm->data_img, int_part(y), x, rst_frc_part(y));
				fill_img(frm->data_img, int_part(y) -1, x, frc_part(y));
			}
			y += slope;
			x++;
		}
	}
	else
	{
		while (x <= xpxl2)
		{
			if (slope > 0)
			{
				fill_img(frm->data_img, x, int_part(y), rst_frc_part(y));
				fill_img(frm->data_img, x, int_part(y) +1, frc_part(y));
			}
			else if (slope <= 0)
			{
				fill_img(frm->data_img, x, int_part(y), rst_frc_part(y));
				fill_img(frm->data_img, x, int_part(y) -1, frc_part(y));
			}
			y += slope;
			x++;
		}
	}
		
}

void	draw_img(t_frame *frm)
{
 	int i = 0;
	int j;
	i = 0;
	while (i < frm->row)
	{
		j = 0;
		while (j < frm->col)
		{
			if (i < frm->row - 1)
				draw_line(frm, frm->vct[i][j].x, frm->vct[i][j].y,
						  frm->vct[i+1][j].x, frm->vct[i+1][j].y);
			if (j < frm->col - 1)
				draw_line(frm, frm->vct[i][j].x, frm->vct[i][j].y,
						  frm->vct[i][j+1].x, frm->vct[i][j + 1].y);
			j++;
		}
		i++;
	}
}
