/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:06:08 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 03:18:57 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**need to carry more info about color
*/

void	fill_img(t_frame *frm, int x, int y, double a)
{
	char	*color;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	if (a == 0)
		return ;
	if ((y * WIN_W + x) * 4 - 1 < 0 ||
		(y * WIN_W + x) * 4 - 1 > WIN_H * WIN_W * 4)
		return ;
	color = &frm->data_img[(y * WIN_W + x) * 4 - 1];
	alpha = 255 * a;
	red = 255;
	green = 255;
	blue = 255;
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue;
}
