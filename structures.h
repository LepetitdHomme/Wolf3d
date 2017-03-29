/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_floor
{
	double			xstart;
	double			ystart;
	double			xw;
	double			yw;
	double			p;
	int				x;
}					t_floor;

typedef struct		s_bmp
{
	int				sign;
	int				sizefile;
	int				reserved1;
	int				offset;
	int				sizehead;
	int				width;
	int				height;
	int				plane;
	int				bpp;
	int				compr;
	int				sizeimg;
	int				xpermeter;
	int				ypermeter;
	int				color;
	int				Fcolor;
	unsigned int	*palette;
}					t_bmp;

typedef struct		s_img
{
	char			*d;
	int				b;
	int				l;
	int				e;
}					t_img;

typedef struct		t_all_data
{
	t_img			w;
	t_img			w2;
	t_img			w3;
	t_img			w4;
	t_img			w5;
	t_img			w6;
	t_img			D;
	t_img			F;
	t_img			S;
}					t_all_data;

typedef struct		s_all_txt
{
	void			*w;
	void			*w2;
	void			*w3;
	void			*w4;
	void			*w5;
	void			*w6;
	void			*D;
	void			*F;
	void			*S;
	void			*dg;
	void			*dg2;
	void			*dg3;
	void			*hud;
}					t_all_txt;

typedef struct		s_spr
{
	void			*d;
	int				w;
	int				h;
}					t_spr;

typedef struct		s_all_spr
{
	t_spr			sg1;
	t_spr			sg2;
	t_spr			sg3;
	t_spr			sg4;
	t_spr			sg5;
	t_spr			sg6;
	t_spr			sg7;
	t_spr			sg8;
	t_spr			sg9;
	t_spr			sg10;
	t_spr			sg11;
	t_spr			dg;
	t_spr			dg2;
	t_spr			dg3;
	t_spr			hud;
}					t_all_spr;

typedef struct		s_key
{
	int				ll;
	int				lr;
	int				ml;
	int				mr;
	int				mf;
	int				mb;
	int				sp;
}					t_key;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			lookx;
	double			looky;
	double			camX;
	int				gridX;
	int				gridY;
	double			FsideX;
	double			FsideY;
	double			dx;
	double			dy;
	int				stepX;
	int				stepY;
	int				touche;
	int				side;
}					t_ray;

typedef struct		s_player
{
	double			x;
	double			y;
	double			lookx;
	double			looky;
	double			scrx;
	double			scry;
}					t_player;

typedef struct		s_tool
{
	double			modulo;
	t_ray			ray;
}					t_tool;

typedef struct		s_mlx
{
	void			*scr;
	void			*win;
	void			*img;
	t_player		*player;
	int				**level;
	t_all_spr		*spr;
	t_all_txt		*txt;
	double			*horizon;
	double			*dist;
	int				*height;
	int				*compass;
	t_tool			*tool;
	t_key			keys;
	int				lvl_h;
	int				lvl_w;
	int				xstart;
	int				ystart;
}					t_mlx;

#endif
