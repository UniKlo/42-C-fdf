/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/02/10 01:05:33 by khou             ###   ########.fr       */
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


void	frame_init(t_frame *frm)
{
	frm->ai_pxl[0].x = 0;
	frm->ai_pxl[0].y = 0;
	frm->ai_pxl[1].x = 0;
	frm->ai_pxl[1].y = 0;
}

void	init(char *str)
{
	while (*str)
		*str++ = '0';
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
	
//    t_frame *frm = malloc(sizeof(t_frame));

	t_frame frm;
	frame_init(&frm);

	if (argc != 2)
	{
		ft_printf("usage: ./fdf [arg]\n");
		exit (1);
	}
	endwith(argv[1], ".fdf");
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
	/*
	int x = 0;
	while (x < (frm.dot_size))
	{
		printf("x: %f, y: %f, z: %f\n",						\
			   frm.vct[x].x, frm.vct[x].y, frm.vct[x].z);
		x++;
	}	
	*/
//---project coordinations to iso measure image size-----------
	project(&frm);
/*
	int i = 0;
	while (i < frm.row)
	{
		int j = 0;
		while (j < frm.col)
		{
			printf("x: %f, y: %f, z: %f ",				\
				   frm.vct[i][j].x, frm.vct[i][j].y, frm.vct[i][j].z);
			j++;
		}
		printf("\n");
		i++;
	}
*/	
//---find out each points in lines and put it in img---------

	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");//open the window
	if (!frm.win)
		ft_printf("error.\n");

//---image------
/*
	frm.img = malloc(sizeof(char) * 4 * WIN_W * WIN_H);
	init(frm.img);
	frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H);
	int bpp = 32;
	int size_line = WIN_W * 4;
	int endian = 1;
	frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian);//big_endian
*/	
//---draw something------------
	draw_img(&frm);//test version, draw from image or put dots
//	mlx_put_image_to_window(frm.mlx, frm.win, frm.img, 0, 0);
//clear_img

	
//---key hook---------	
	mlx_key_hook(frm.win, deal_key, (void *)0);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);
	free_vct(&frm);

	return (0);
}
