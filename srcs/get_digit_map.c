/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 01:23:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/12 12:46:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recenter(t_frame *frm)
{
	int y0 = frm->row/2;
    int x0 = frm->col/2;
	frm->center[0].x = WIN_W/2 - frm->vct[y0][x0].x;
	frm->center[0].y = WIN_H/2 - frm->vct[y0][x0].y;
//	frm->center.z = 0.8;
	int i = 0;
	while (i < frm->row)
	{
		int j = 0;
		while (j < frm->col)
		{
			frm->vct[i][j].x += frm->center[0].x + frm->center[1].x;
			frm->vct[i][j].y += frm->center[0].y + frm->center[1].y;
			//* frm->center.z;
			j++;
		}
		i++;
	}
}

void	get_coordinates(char *str, t_frame *frm)
{
	int fd;
	fd = open(str, O_RDONLY);
    char	*line = NULL;

	int i = 0;//index of the array of struct
	int j;
	int z;
	
	frm->vct = malloc(sizeof(t_vct *) * frm->row);
	while (get_next_line(fd, &line))
	{
		frm->vct[i] =  malloc(sizeof(t_vct) * frm->col);
		j = 0;
		while(getnbr(&line, &z) && j < frm->col)
		{
			frm->vct[i][j].x = j;
			frm->vct[i][j].y = i;
			frm->vct[i][j].z = z;
			j++;
		}
		i++;
	}
	close(fd);
}

void get_map_size(char *str, t_frame *frm)
{
	int fd;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("Error");//?
		exit (0);
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
}

void	get_digit_map(char *str, t_frame *frm)
{
	get_map_size(str, frm);
	get_coordinates(str, frm);
	stage(frm);
}
