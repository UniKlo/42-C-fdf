/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/02/12 13:48:57 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		deal_key(int key, t_frame *frm)
{
	ft_printf("Hello\n");
	ft_putstr("world\n");
	if (key == ESC_KEY)
		  exit(0);
	if (key == RIGHT_KEY)
		frm->center[1].x += 5;
	//stage(frm);
	return (0);
}

int mlx_hook(void *win, int x_event, int x_mask, int (*funct)(), void *param);


void	frame_init(t_frame *frm)
{
	frm->ai_pxl[0].x = 0;
	frm->ai_pxl[0].y = 0;
	frm->ai_pxl[1].x = 0;
	frm->ai_pxl[1].y = 0;


	frm->center[0].x = 0;//distance to center
	frm->center[0].y = 0;//distance to center
	frm->center[0].z = 0;
	frm->center[1].x = 0;// move right < 1, move left > 1
	frm->center[1].y = 0;// move up < 1, move down > 1
	frm->center[1].z = 0.2;//deepth 
}

void	free_vct(t_frame *frm)
{
	int i = 0;
	int j;
	while (i< frm->row)
	{
		j = 0;
		while(j < frm->col)
		{
			free(&frm->vct[i][j]);
//				 .x);
//			frm->vct[i][j].y;
//			frm->vct[i][j].z;
			j++;
		}
		i++;
		
	}
}

void	endwith(char *str, char *word)
{
	int l_str = ft_strlen(str);
	int l_wrd = ft_strlen(word);
	while (word[l_wrd-1] == str[l_str-1])
	{
		l_wrd--;
		l_str--;
	}
	if (l_wrd != 0)
	{
		ft_printf("Error: Not a %s file\n", word);
		exit(0);
	}
}

int main(int argc, char **argv)
{
	t_frame frm;
	frame_init(&frm);
//Error massage
	if (argc != 2)
	{
		ft_printf("usage: ./fdf [arg]\n");
		exit (0);
	}
	endwith(argv[1], ".fdf");
//---windows------
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");//open the window
	if (!frm.win)
		ft_printf("error.\n");

//---image------
	if (!(frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H)))
		exit(0);
	int bpp; // = 32;
	int size_line; // = WIN_W * 4;
	int endian; // = 0;
	if(!(frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian)))
		exit(0);

//---initial position-----
	get_digit_map(argv[1], &frm);
	
//	rotate(&frm);
//	project(&frm);
//---draw something------------
//	draw_img(&frm);//test version, draw from image or put dots
	mlx_put_image_to_window(frm.mlx, frm.win, frm.img, 0, 0);
//clear_img

	
//---key hook---------	
	mlx_key_hook(frm.win, deal_key, (void *)0);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);

//---after exit-------
	mlx_destroy_image(frm.mlx, frm.img);
	free_vct(&frm);//free the part that have been malloced in frame

	return (0);
}
