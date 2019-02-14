/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 01:23:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/13 18:55:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinates(char *str, t_frame *frm)
{
	int fd;
	fd = open(str, O_RDONLY);
    char	*line = NULL;

	int i = 0;//index of the array of struct
	int j;
	int z;
	
	frm->org = malloc(sizeof(t_vct *) * frm->row);
	while (get_next_line(fd, &line))
	{
		frm->org[i] =  malloc(sizeof(t_vct) * frm->col);
		j = 0;
		while(getnbr(&line, &z) && j < frm->col)
		{
			frm->org[i][j].x = j;
			frm->org[i][j].y = i;
			frm->org[i][j].z = z;
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
//		printf("%s\n", line);
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
	render(frm);
}
