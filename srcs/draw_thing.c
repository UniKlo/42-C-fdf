

#include "fdf.h"
/*
//image version
void	plot(char *data_img, int x, int y, float a)//a need to carry more info about color
{
	char *color = &data_img[x + 4* WIN_W * y];
	int alpha = 255 * a;	
	int red = 255;
	int green = 255;
	int blue = 255;

	*color++ = alpha * a;
	*color++ = red;
	*color++ = green;
	*color = blue;	
}
*/

//easy version

void    plot(t_frame *frm, int x, int y, float a)
{
	int color = 0;
	int red = 255;
    int blue = 255;
    int green = 255;
    int alpha = 255 * a;

	color += alpha << 24;
	color += red << 16;
	color += green << 8;
	color += blue;
	
	mlx_pixel_put(frm->mlx, frm->win, x, y, color);
}

void	swap(int *a, int *b)
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
void	draw_line(t_frame *frm, int x1, int y1, int x2, int y2)//change them all to float. projection points could be float.
{
	int steep = abs(y1 - y2) > abs(x1 - x2) ? 1 : 0;
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

//	int	xend = round(x1);
//	int yend = y1 + slope * (x1 - xend);
	int		xpxl1 = x1;
	int		xpxl2 = x2;
	float	y = y1;

	int		x = xpxl1;
	 
	if (steep)
	{
		while (x <= xpxl2)
		{
			plot(frm, int_part(y), x, rst_frc_part(y));
			plot(frm, int_part(y) + 1, x, frc_part(y)); //does it matter +-??
			//in relate to slope sign
/*
			if (slope > 0)
			{
//				plot(frm->data_img, int_part(y), x, rst_frc_part(y));
//				plot(frm->data_img, int_part(y) +1, x, frc_part(y));
				plot(frm, int_part(y), x, rst_frc_part(y));
				plot(frm, int_part(y) +1, x, frc_part(y));
			}
			else if (slope <= 0)
			{
//				plot(frm->data_img, int_part(y), x, rst_frc_part(y));
//				plot(frm->data_img, int_part(y) -1, x, frc_part(y));
				plot(frm, int_part(y), x, rst_frc_part(y));
				plot(frm, int_part(y) -1, x, frc_part(y));
			}
*/
			y += slope;
			x++;
		}
	}
	else
	{
		while (x <= xpxl2)
		{
			plot(frm, x, int_part(y), rst_frc_part(y));
			plot(frm, x, int_part(y) + 1, frc_part(y));
/*
			if (slope > 0)
			{
//				plot(frm->data_img, x, int_part(y), rst_frc_part(y));
//				plot(frm->data_img, x, int_part(y) +1, frc_part(y));
				plot(frm, x, int_part(y), rst_frc_part(y));
				plot(frm, x, int_part(y) +1, frc_part(y));
			}
			else if (slope <= 0)
			{
//				plot(frm->data_img, x, int_part(y), rst_frc_part(y));
//				plot(frm->data_img, x, int_part(y) -1, frc_part(y));
				plot(frm, x, int_part(y), rst_frc_part(y));
				plot(frm, x, int_part(y) -1, frc_part(y));
			}
*/
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
				draw_line(frm, frm->dots[i][j].x, frm->dots[i][j].y,
						  frm->dots[i+1][j].x, frm->dots[i+1][j].y);
			if (j < frm->col - 1)
				draw_line(frm, frm->dots[i][j].x, frm->dots[i][j].y,
						  frm->dots[i][j+1].x, frm->dots[i][j + 1].y);
			j++;
		}
		i++;
	}
}
