#include "fdf.h"

void    draw(t_frame *frm)
{
    int x = 145;
    int y = 150;
    while (x < 146)
    {
        mlx_pixel_put(frm->mlx, frm->win, x++, y, 0xFFFFFF);
    }
}

