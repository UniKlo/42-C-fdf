

#include "fdf.h"

//image version
void	plot(char *data_img, int x, int y, float a)//a need to carry more info about color
{
	int position = (y * WIN_W + x) * 4 - 1;
	if (position < 0 || position > WIN_H * WIN_W * 4)
		return ;
	char *color = &data_img[position];
	int alpha = 255 * a;	
	int red = 255;
	int green = 255;
	int blue = 255;

//	printf("alpha: %d\n", alpha);
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue; 
 }

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
				plot(frm->data_img, int_part(y), x, rst_frc_part(y));
				plot(frm->data_img, int_part(y) +1, x, frc_part(y));
			}
			else if (slope <= 0)
			{
				plot(frm->data_img, int_part(y), x, rst_frc_part(y));
				plot(frm->data_img, int_part(y) -1, x, frc_part(y));
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
				plot(frm->data_img, x, int_part(y), rst_frc_part(y));
				plot(frm->data_img, x, int_part(y) +1, frc_part(y));
			}
			else if (slope <= 0)
			{
				plot(frm->data_img, x, int_part(y), rst_frc_part(y));
				plot(frm->data_img, x, int_part(y) -1, frc_part(y));
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
