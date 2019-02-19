/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:19 by khou              #+#    #+#             */
/*   Updated: 2019/02/19 03:15:33 by khou             ###   ########.fr       */
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
# define MN_KEY 27
# define PL_KEY 24

/*
** Letters keys
*/

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define W_KEY 13
# define E_KEY 14
# define R_KEY 15

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
	double		x;
	double		y;
	double		z;
	int			c;
}				t_vct;

typedef struct	s_frame
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_img;
	int			col;
	int			row;
	int			dot_size;
	int			scale;
	t_vct		**org;
	t_vct		**vct;
	t_vct		ai_z;//max, min, width, hight, need to init
	t_vct		center[2];
	t_vct		ang;
	int		steep;
	double	slope;
	int			pxl_size;
}				t_frame;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

void			get_digit_map(char *str, t_frame *frm);
int				render(t_frame *frm);
void			scale(t_frame *frm);
double			radian_ang(int angle);
void			rotate(t_frame *frm);
void			project(t_frame *frm);
void			recenter(t_frame *frm);
void			draw_line(t_frame *frm, t_vct p1, t_vct p2);
void			fill_img(t_frame *frm, int x, int y, double a);
int				deal_key(int key, t_frame *frm);
int				deal_mouse(int mouse, int x, int y,t_frame *frm);
int				red_close(t_frame *frm);
void			frame_init(t_frame *frm);
#endif
