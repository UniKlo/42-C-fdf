/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:19 by khou              #+#    #+#             */
/*   Updated: 2018/12/02 15:29:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/include/printf.h"
# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
//# include 

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_frame
{
	void		*mlx;
	void		*win;
  //	t_plist		plist; //size & t_point *list
}			t_frame;

typedef struct	s_point3d
{
				int x;
				int y;
				int z;
}				t_point3d;

# define KEY_ESC 53


/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void draw(t_frame *frm);

#endif
