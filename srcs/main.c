/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/01/02 18:19:10 by khou             ###   ########.fr       */
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
//---open file----
	int fd;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit (1);
	char	*line = NULL;
	int row_size = 0;
	int column_size = 0;
	int n;
	while (get_next_line(fd, &line))
	{
		row_size++;
		printf("%s\n", line);
	}
	while (getnbr(&line, &n)) 
		column_size++;
	close (fd);
	printf("nbr of row: %d, nbr of column: %d\n", row_size, column_size);
//---create array of coordination-----------
	int i;//column
	int j = 0;//row
	int k = 0;//index of the array of struct
	t_point3d *point_list = malloc(sizeof(t_point3d) * (row_size * column_size));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
        exit (1);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while(getnbr(&line, &n))
		{
			point_list[k].x = i;
			point_list[k].y = j;
			point_list[k].z = n;
			i++;
			k++;
		}
		j++;
	}
	close(fd);
	i = 0;
	while (i < (row_size * column_size))
	{
		printf("x: %d, y: %d, z: %d\n",\
			   point_list[i].x, point_list[i].y, point_list[i].z);
		i++;
	}
//---adjust the coordination with the rotation

	

	
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
