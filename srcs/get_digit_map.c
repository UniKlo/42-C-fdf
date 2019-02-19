/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 01:23:44 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 02:40:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_coordinates(char **line, t_vct *org, int i, int j)
{
	int	z;

	getnbr(line, &z);
	org->x = j;
	org->y = i;
	org->z = z;
	org->c = 0;
	if (**line == ',')
	{
		*line += 3;
		org->c = ft_atoi_base(*line, 16);
		*line += ft_nbrlen_base(org->c, 16);
	}
}

void	malloc_map(char *str, t_frame *frm)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	*tmp;

	line = NULL;
	fd = open(str, O_RDONLY);
	i = 0;
	frm->org = malloc(sizeof(t_vct *) * frm->row);
	while (get_next_line(fd, &line))
	{
		frm->org[i] = malloc(sizeof(t_vct) * frm->col);
		j = 0;
		tmp = line;
		while (j < frm->col)
		{
			get_coordinates(&line, &frm->org[i][j], i, j);
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

	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("Error");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if (frm->col != 0 && frm->col != ft_count_nbr_block(line, ' '))
		{
			printf("Not a rectangle\n");
			exit(0);
		}
		frm->col = ft_count_nbr_block(line, ' ');
		frm->row++;
		free(line);
	}
	close(fd);
	frm->dot_size = frm->row * frm->col;
	printf("nbr of row: %d, nbr of column: %d\n", frm->row, frm->col);
}

void	get_digit_map(char *str, t_frame *frm)
{
	get_map_size(str, frm);
	malloc_map(str, frm);
}
