/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2018/11/27 19:23:08 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	param = 0;
	ft_printf("Hello\n");
	ft_putstr("world\n");
	if (key == KEY_ESC)
		  exit(0);
	return (0);
}

int mlx_hook(void *win, int x_event, int x_mask, int (*funct)(), void *param);

int main()
{
    t_frame frm;

//	frame_init(&frm);
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, 480, 300, "The VIEW");//open the window
	if (!frm.win)
		ft_printf("error.\n");
	//image
	//draw something
	draw(&frm);
//	mlx_pixel_put(frm.mlx, frm.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(frm.win, deal_key, (void *)0);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);
	return (0);
}
