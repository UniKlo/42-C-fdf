/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2019/01/09 12:35:46 by khou             ###   ########.fr       */
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
	int z;
	while (get_next_line(fd, &line))
	{
		row_size++;
		printf("%s\n", line);
	}
	while (getnbr(&line, &z)) 
		column_size++;
	close (fd);
	printf("nbr of row: %d, nbr of column: %d\n", row_size, column_size);
//---create array of coordination-----------
	int x;//column
	int y = 0;//row
	int k = 0;//index of the array of struct
	t_point3d *point_list = malloc(sizeof(t_point3d) * (row_size * column_size));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
        exit (1);
	while (get_next_line(fd, &line))
	{
		x = 0;
		while(getnbr(&line, &z))
		{
			point_list[k].x = x;
			point_list[k].y = y;
			point_list[k].z = z;
			x++;
			k++;
		}
		y--;
	}
	close(fd);
//---print out coordinations-----------
	x = 0;
	while (x < (row_size * column_size))
	{
		printf("x: %d, y: %d, z: %d\n",\
			   point_list[x].x, point_list[x].y, point_list[x].z);
		x++;
	}
//---adjust the coordination with the rotation------

	//rotate along z
	x = 0;
	float	angle = 30; 
	t_vect *z_rot = malloc(sizeof(t_vect) * (row_size * column_size));
	printf("sin(angle): %f, cos(angle): %f\n", sin(angle), cos(angle));
	while (x < (row_size * column_size))
	{
		z_rot[x].x = point_list[x].x * cos(angle) - point_list[x].y * sin(angle);
		z_rot[x].y = point_list[x].x * sin(angle) + point_list[x].y * cos(angle);
		z_rot[x].z = point_list[x].z;
		x++;
	}

//---print out coordinations-----------
	x = 0;
	while (x < (row_size * column_size))
	{
		printf("x: %f, y: %f, z: %f\n",\
			   z_rot[x].x, z_rot[x].y, z_rot[x].z);
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
	//draw something
	draw(&frm);
//	mlx_pixel_put(frm.mlx, frm.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(frm.win, deal_key, (void *)0);
//	mlx_hook(win, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(frm.mlx);
	return (0);
}
