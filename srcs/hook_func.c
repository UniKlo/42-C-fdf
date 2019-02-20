/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:25:14 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 16:25:17 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_frame *frm)
{
	ft_printf("pressed a key-------------------\n");
	key == ESC_KEY ? red_close(frm) : 0;
	key == RIGHT_KEY ? frm->center[1].x += 5 : 0;
	key == LEFT_KEY ? frm->center[1].x -= 5 : 0;
	key == DOWN_KEY ? frm->center[1].y += 5 : 0;
	key == UP_KEY ? frm->center[1].y -= 5 : 0;
	key == A_KEY ? frm->ang.y -= 1 : 0;
	key == D_KEY ? frm->ang.y += 1 : 0;
	key == W_KEY ? frm->ang.x -= 1 : 0;
	key == S_KEY ? frm->ang.x += 1 : 0;
	key == Q_KEY ? frm->ang.z -= 1 : 0;
	key == E_KEY ? frm->ang.z += 1 : 0;
	key == R_KEY ? frame_init(frm) : 0;
	key == MN_KEY ? frm->center[0].z -= 0.01 : 0;
	key == PL_KEY ? frm->center[0].z += 0.01 : 0;
	return (0);
}

int		deal_mouse(int mouse, int x, int y, t_frame *frm)
{
	ft_printf("touched a mouse------------------\n");
	x = 0;
	y = 0;
	mouse == SCROLLUP_KEY ? frm->center[1].z += 1 : 0;
	mouse == SCROLLDOWN_KEY ? frm->center[1].z -= 1 : 0;
	return (0);
}

int		red_close(t_frame *frm)
{
	mlx_destroy_image(frm->mlx, frm->img);
	exit(0);
	return (0);
}
