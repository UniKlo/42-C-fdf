/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/02/15 16:54:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**frm->center[0].x	distance to center
**frm->center[0].y	distance to center
**frm->center[0].z	deepth of z
**frm->center[1].x	move right < 1, move left > 1
**frm->center[1].y	move up < 1, move down > 1
**frm->center[1].z	further < 0, closer > 0
*/



void	frame_init(t_frame *frm)
{
	frm->ai_pxl[0].x = 0;
	frm->ai_pxl[0].y = 0;
	frm->ai_pxl[1].x = 0;
	frm->ai_pxl[1].y = 0;


	frm->center[0].x = 0;
	frm->center[0].y = 0;
	frm->center[0].z = 0.2;
	frm->center[1].x = 0;
	frm->center[1].y = 0;
	frm->center[1].z = 0;
	frm->ang.x = 5;
	frm->ang.y = 5;
	frm->ang.z = 5;
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
			free(&frm->org[i][j].x);
			free(&frm->org[i][j].y);
			free(&frm->org[i][j].z);
			free(&frm->vct[i][j].x);
			free(&frm->vct[i][j].y);
			free(&frm->vct[i][j].z);
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
	int bpp;
	int size_line;
	int endian;
	if(!(frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian)))
		exit(0);

//---initial position-----
	get_digit_map(argv[1], &frm);

	
//---key hook---------	
	mlx_hook(frm.win, 2, 0, deal_key, &frm);
	mlx_hook(frm.win, 4, 0, deal_mouse, &frm);
	mlx_hook(frm.win, 17, 0, red_close, &frm);
	mlx_loop_hook(frm.mlx, render, &frm);
	mlx_loop(frm.mlx);

//---after exit-------
	mlx_destroy_image(frm.mlx, frm.img);
	free_vct(&frm);//free the part that have been malloced in frame

	return (0);
}
