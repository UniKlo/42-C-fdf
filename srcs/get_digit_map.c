/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 01:23:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 01:22:16 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinates(char *str, t_frame *frm)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	int		z;

	line = NULL;
	fd = open(str, O_RDONLY);
	i = 0;
	frm->org = malloc(sizeof(t_vct *) * frm->row);
	while (get_next_line(fd, &line))
	{
		frm->org[i] = malloc(sizeof(t_vct) * frm->col);
		j = 0;
		char *tmp = line;
		while (getnbr(&line, &z) && j < frm->col)
		{
			frm->org[i][j].x = j;
			frm->org[i][j].y = i;
			frm->org[i][j].z = z;
			frm->org[i][j].c = 0;
			if (*line == ',')
			{
				line += 3;
//				printf("line: %.10s\n", line);
//				printf("nbr_before: %d, ", ft_atoi_base(line, 16));
				frm->org[i][j].c = ft_atoi_base(line, 16);
//				printf("nbr_after: %d, ", frm->org[i][j].c);
				line += ft_nbrlen_base(frm->org[i][j].c, 16);
//				printf("nbrlen: %d, %.20s\n",
//					   ft_nbrlen_base(frm->org[i][j].c, 16), line);
//				while (1);
				}
//s			printf("z: %f, c: %d\n", frm->org[i][j].z, frm->org[i][j].c);
			j++;
		}
		free(tmp);
		i++;
	}
	close(fd);
}


void	get_map_size(char *str, t_frame *frm)
{
	int		fd;
	char	*line;
	int		row_size;
	int		column_size;
	
	line = NULL;
	row_size = 0;
	column_size = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("Error");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if (column_size != 0 && column_size != ft_count_nbr_block(line, ' '))
		{
			printf("Not a rectangle\n");
			exit(0);
		}
		column_size = ft_count_nbr_block(line, ' ');
		row_size++;
		free(line);
	}
	close(fd);
	frm->col = column_size;
	frm->row = row_size;
	frm->dot_size = row_size * column_size;
	printf("nbr of row: %d, nbr of column: %d\n", row_size, column_size);
}

void	get_digit_map(char *str, t_frame *frm)
{
	get_map_size(str, frm);
	get_coordinates(str, frm);
}
