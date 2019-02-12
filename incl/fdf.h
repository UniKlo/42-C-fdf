/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:19 by khou              #+#    #+#             */
/*   Updated: 2019/02/12 14:38:11 by khou             ###   ########.fr       */
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

# define WIN_W 1920
# define WIN_H 1080

/*
** Keyboard keys
*/

# define ESC_KEY 53

/*
** Letters keys
*/

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

/*
** Arrow keys
*/

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

/*
** Mouse button keycodes
*/

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct	s_vct
{
	float		x;
	float		y;
	float		z;
}				t_vct;

typedef struct		s_frame
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_img;
	int			col;
	int			row;
	int			dot_size;
	int				scale;
	t_vct	**vct;
	t_vct	ai_pxl[2];//max, min, width, hight, need to init
	t_vct	center[2];
	int			pxl_size;
  //	t_plist		plist; //size & t_point *list
}			t_frame;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void	get_digit_map(char *str, t_frame *frm);
void	render(t_frame *frm);
void	scale(t_frame *frm);
void	recenter(t_frame *frm);
void	rotate(t_frame *frm);
void	project(t_frame *frm);
void	recenter(t_frame *frm);
void    draw_img(t_frame *frm);
#endif
