/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:06:08 by khou              #+#    #+#             */
/*   Updated: 2019/02/15 16:00:48 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(char *data_img, int x, int y, float a)//a need to carry more info about color
{
	int position = (y * WIN_W + x) * 4 - 1;
	if (position < 0 || position > WIN_H * WIN_W * 4)
		return ;
	char *color = &data_img[position];
	int alpha = 255 * a;
	int red = 255;
	int green = 255;
	int blue = 255;

//	printf("alpha: %d\n", alpha);
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue;
 }
