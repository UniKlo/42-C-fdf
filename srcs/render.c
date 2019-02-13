/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:34:30 by khou              #+#    #+#             */
/*   Updated: 2019/02/12 19:01:14 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_frame *frm)
{
	scale(frm);
	rotate(frm);
	project(frm);
	recenter(frm);
	draw_img(frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img, 0, 0);	
}
