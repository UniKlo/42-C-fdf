/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/02/13 18:49:22 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_frame *frm)
{
	int i = 0;
	while ( i < WIN_W * WIN_H * 4)
		frm->data_img[i++] = 0;
}



int		deal_key(int key, t_frame *frm)
{
	ft_printf("pressed a key-------------------\n");
	if (key == ESC_KEY)
		  exit(0);
	
	if (key == RIGHT_KEY)
		frm->center[1].x += 5;
	if (key == LEFT_KEY)
		frm->center[1].x -= 5;
	if (key == DOWN_KEY)
		frm->center[1].y += 5;
	if (key == UP_KEY)
		frm->center[1].y -= 5;
	clear_img(frm);
	render(frm);
	return (0);
}

int		deal_mouse(int mouse, t_frame *frm)
{
	ft_printf("touched a mouse------------------\n");
	if (mouse == SCROLLUP_KEY)
		frm->center[1].z += 5;
	if (mouse == SCROLLDOWN_KEY)
		frm->center[1].z -= 5;
	clear_img(frm);
	render(frm);
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
	frm->center[0].z = 0;//deepth of z?!
	frm->center[1].x = 0;// move right < 1, move left > 1
	frm->center[1].y = 0;// move up < 1, move down > 1
	frm->center[1].z = 0;// move far < 0, close > 0
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
	mlx_key_hook(frm.win, deal_key, &frm);
	mlx_mouse_hook(frm.win, deal_mouse, &frm);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);

//---after exit-------
//	mlx_destroy_image(frm.mlx, frm.img);
	free_vct(&frm);//free the part that have been malloced in frame

	return (0);
}
