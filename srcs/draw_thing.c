#include "fdf.h"

void    draw(t_frame *frm)
{
    int x = WIN_W/2;//starting point
    int y = WIN_H/2;//starting point
	int unit = 0;//unit line length

	printf("h: %d, w: %d\n", WIN_H/(frm->row), WIN_W/(frm->col));
	unit = WIN_H/(frm->row) >= WIN_W/(frm->col) ? WIN_W/(frm->col) : WIN_H/(frm->row);
	printf("unit: %d\n", unit);
	while ((x - WIN_W/2) < unit)
        mlx_pixel_put(frm->mlx, frm->win, x++, y, 0xFFFFFF);
	x = WIN_W/2;
	while ((y - WIN_H/2) < unit)
        mlx_pixel_put(frm->mlx, frm->win, x, y++, 0xFFFFFF);

/*
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
		}*/
}
