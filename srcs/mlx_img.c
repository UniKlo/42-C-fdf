/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:06:08 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 02:40:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**need to carry more info about color
*/

void	fill_img(t_frame *frm, int x, int y, double a)
{
	int		position;
	char	*color;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	if (a == 0)
		return ;
	position = (y * WIN_W + x) * 4 - 1;
	if (position < 0 || position > WIN_H * WIN_W * 4)
		return ;
	color = &frm->data_img[position];
	alpha = 255 * a;
	red = 255;
	green = 255;
	blue = 255;
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue;
}
