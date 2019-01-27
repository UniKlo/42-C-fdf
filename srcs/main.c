/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/01/26 02:27:00 by khou             ###   ########.fr       */
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

#include <stdio.h>

int main(int argc, char **argv)
{
	
    t_frame frm;

	if (argc != 2)
		exit (1);
	get_digit_map(argv[1], &frm);
/*
//---print out Orignal coordinations-----------
	
	int i = 0;
	while (i < frm.row)
	{
		int j = 0;
		while (j < frm.col)
		{
			printf("x: %d, y: %d, z: %d\n",								\
				   frm.dots[i][j].x, frm.dots[i][j].y, frm.dots[i][j].z);
			j++;
		}
		i++;
	}
*/

	stage(&frm);

//---print out ROTATED coordinations-----------
	int x = 0;
	while (x < (frm.dot_size))
	{
		printf("x: %f, y: %f, z: %f\n",\
			   frm.vct[x].x, frm.vct[x].y, frm.vct[x].z);
		x++;
	}	

	
//---project coordinations to iso and store as image-----------
//---draw lines---------

	
//	frame_init(&frm);
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");//open the window
	if (!frm.win)
		ft_printf("error.\n");
	//image
	frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H);
//	frm.data_img = mlx_get_data_addr(frm.img, 32, WIN_W * 4, &endian);
	//draw something
//	draw(&frm);
	mlx_key_hook(frm.win, deal_key, (void *)0);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);
	return (0);
}
