#include "fdf.h"

void    draw(t_frame *frm)
{
    int x = 100;
    int y = 150;
    while (x < 300)
    {
        mlx_pixel_put(frm->mlx, frm->win, x++, y, 0xFFFFFF);
    }
}

