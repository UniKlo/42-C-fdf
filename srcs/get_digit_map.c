/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 01:23:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/08 15:45:04 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recenter(t_frame *frm)
{
	int x0 = frm->col/2;
    int y0 = frm->row/2;
	int dx = WIN_W/2 - frm->dots[x0][y0].x;
	int dy = WIN_H/2 - frm->dots[x0][y0].y;

	int i = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			frm->dots[i][j].x += dx;
			frm->dots[i][j].y += dy;
			j++;
		}
		i++;
	}
}

void	apply_scale(t_frame *frm, int i, int j)
{

	if (i >= frm->row || j >= frm->col)
		 return ;
//	printf("i: %d, j: %d\n", i ,j);
	frm->dots[i][j].x = j * frm->scale;
	frm->dots[i][j].y = i * frm->scale;
//	frm->dots[i][j].z = frm->dots[i][j].z * frm->scale;
	apply_scale(frm, i + 1, j);
	apply_scale(frm, i, j + 1);
}

void	scale(t_frame *frm)
{
	int unit_row = WIN_H*0.6/(frm->row);
	int	unit_col = WIN_W*0.6/(frm->col);
	frm->scale = unit_row <= unit_col ? unit_row : unit_col; 
	printf("scale: %d\n", frm->scale);
	int i = 0;
	int j = 0;
	apply_scale(frm, i, j);
}

void	get_coordinates(char *str, t_frame *frm)
{
	int fd;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("Error");//?
		exit (1);
	}
    char	*line = NULL;

	int i = 0;//index of the array of struct
	int j;
	
	frm->dots = malloc(sizeof(t_dot *) * frm->row);
	if ((fd = open(str, O_RDONLY)) == -1)
        exit (1);
	while (get_next_line(fd, &line))
	{
		frm->dots[i] =  malloc(sizeof(t_dot) * frm->col);
		j = 0;
		while(getnbr(&line, &frm->dots[i][j].z) && j < frm->col)
		{
			frm->dots[i][j].x = j;
			frm->dots[i][j].y = i;
			j++;
		}
		i++;
	}
	close(fd);
	scale(frm);
}

void get_digit_map(char *str, t_frame *frm)
{
	int fd;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("Error");//?
		exit (1);
	}
    char	*line = NULL;
    int		row_size = 0;
    int		column_size = 0;
    int		z;
	while (get_next_line(fd, &line))
	{
		row_size++;
		printf("%s\n", line);
	}
	while (getnbr(&line, &z))
		column_size++;
	close (fd); //size of malloc based on rows and colu of the last row.
	frm->col = column_size;
	frm->row = row_size;
	frm->dot_size = row_size * column_size; 
	printf("nbr of row: %d, nbr of column: %d\n", row_size, column_size);
	get_coordinates(str, frm);
	recenter(frm);
}
