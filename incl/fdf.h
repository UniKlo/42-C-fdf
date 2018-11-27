/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:19 by khou              #+#    #+#             */
/*   Updated: 2018/10/27 21:42:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "../libft/include/printf.h"
# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
//# include 

# define KEY_ESC 53


typedef struct		s_frame
{
	void		*mlx;
	void		*win;
  //	t_plist		plist; //size & t_point *list
}			t_frame;
 
void draw(t_frame *frm);

#endif
