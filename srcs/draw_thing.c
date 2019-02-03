

#include "fdf.h"

/*
void	plot(char *data_img, int x, int y, int a)//a need to carry more info about color
{
	char *color = data_img[x + 4* WIN_W * y];
	int red = 255;
	int blue = 255;
	int green = 255;
	int alpha = 255;

	*color++ = red;
	*color++ = blue;
	*color++ = green;
	*color = alpha;
	
}
*/

void	draw_line(t_frame *frm, int x1, int y1, int x2, int y2)
{
	int		dx = x1 - x2;
	int		dy = y1 - y2;
	printf("abs: %d\n", abs(dx));
	int steep = abs(dy) > abs(dx) ? 1 : 0;
	printf("steep: %d\n", steep);
	if (steep)
	{
	}
	/*
	if (fabs(dx) > fabs(dy))
		;
	else
	steep;
*/
	
}

int	main()
{
	draw_line(NULL, 10, 30, 800, 900);
	return (0);
}
/*
void	fill_img(t_frame *frm, int i, int j)
{
	int	x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	x1 = frm->dots[i][j].x;
	y1 = frm->dots[i][j].y;
	if ((i + 1) >= frm->col || (j + 1) >= frm->row)
		 return ;
	if ((j+1) < frm->col)
	{
		x2 = frm->dots[i][j+1].x;
		y2 = frm->dots[i][j+1].y;
		draw_line(frm, x1, y1, x2, y2);
	}
	if ((i+1) < frm->col)
	{
		x2 = frm->dots[i+1][j].x;
		y2 = frm->dots[i+1][j].y;
		draw_line(frm, x1, y1, x2, y2);
	}
	fill_img(frm, i + 1, j);
	fill_img(frm, i, j + 1);
}
*/





















/*
void    draw(t_frame *frm)
{
    int x = WIN_W/2;//starting point
    int y = WIN_H/2;//starting point
	int unit = 0;//unit line length

	printf("h: %d, w: %d\n", WIN_H/(frm->row), WIN_W/(frm->col));
	unit = WIN_H/(frm->row) >= WIN_W/(frm->col) ? WIN_W/(frm->col) : WIN_H/(frm->row);
	printf("unit: %d\n", unit);
	while ((x - WIN_W/2) < unit)
        mlx_pixel_put(frm->mlx, frm->win, x++, y++, 0xFFFFFF);
//	x = WIN_W/2;
//	while ((y - WIN_H/2) < unit)
//        mlx_pixel_put(frm->mlx, frm->win, x, y++, 0xFFFFFF);

void    draw(t_frame *frm, int x, int y)
{
	mlx_pixel_put(frm->mlx, frm->win, x++, y, 0xFFFFFF);
}

void    draw_bresenham(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int dx2 = dx <<1;//x偏移量乘2
	int dy2 = dy <<1;//y偏移量乘2
	int e = -dx; //e = -0.5 * 2 * dx,把e 用2 * dx* e替换
	int x = x0；//起点x坐标
	int y = y0;//起点y坐标
	for (x = x0; x < x1;x++)
	{
		printf ("%d,%d\n",x, y);
		e=e + dy2;//来自 2*e*dx= 2*e*dx + 2dy  （原来是 e = e + k）
		if (e > 0)//e是整数且大于0时表示要取右上的点（否则是右下的点） 
		{ 
		 	y++;
			
			e= e - dx2;//2*e*dx = 2*e*dx - 2*dx  (原来是 e = e -1)
		}
		}
}
*/
