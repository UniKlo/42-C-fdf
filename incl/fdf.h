/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:19 by khou              #+#    #+#             */
/*   Updated: 2019/01/26 02:06:45 by khou             ###   ########.fr       */
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
# include <math.h>

/*
** ----------------------------- Definition ------------------------------------
*/

# define KEY_ESC 53
# define WIN_W 1920
# define WIN_H 1080

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct		s_frame
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_img;
	int			col;
	int			row;
	int			dot_size;
	struct s_dot	**dots;
	int				scale;
	struct s_vct	*vct;
  //	t_plist		plist; //size & t_point *list
}			t_frame;

typedef struct	s_dot
{
	int		x;
	int		y;
	int		z;
}				t_dot;

typedef struct	s_vct
{
	float		x;
	float		y;
	float		z;
}				t_vct;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void draw(t_frame *frm);
void get_digit_map(char *str, t_frame *frm);
void    stage(t_frame *frm);
#endif
