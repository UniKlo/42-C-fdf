/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:21:38 by khou              #+#    #+#             */
/*   Updated: 2018/10/27 21:44:02 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		deal_key(int key, void *param)
{
	param = 0;
	ft_printf("Hello\n");
	ft_putstr("world\n");
	if (key == 53)
		exit(0);
	return (0);
}

int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "The VIEW");//open the window
	if (!win_ptr)
		ft_printf("error.\n");
	//image
	//draw something
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_hook(win_ptr, x_event, x_mask, (*funct)(), (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
