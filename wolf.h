/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/31 08:16:22 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/libft.h"
# include "X11/mlx.h"
# include "structures.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include <time.h>

# define DEBUG printf("%s %d\n", __FILE__, __LINE__)

# ifdef __linux__
	# define LOOK_LEFT 65361
	# define LOOK_RIGHT 65363
	# define MOVE_FORWARD 119
	# define MOVE_BACKWARD 115
	# define MOVE_LEFT 97
	# define MOVE_RIGHT 100
	# define KEY_TXT 116
	# define KEY_TXTF 102
	# define KEY_ESC 65307
	# define SPACE 32
# elif __APPLE__
	# define LOOK_LEFT 123
	# define LOOK_RIGHT 124
	# define MOVE_FORWARD 13
	# define MOVE_BACKWARD 1
	# define MOVE_LEFT 0
	# define MOVE_RIGHT 2
	# define KEY_TXT 17
	# define KEY_TXTF 3
	# define KEY_ESC 53
	# define KEY_SPACE 49
# endif

# define ANGLE M_PI_2
# define UNITE 64
# define SCR_H 640
# define SCR_W 896
# define ROT 0.08
# define SPEED 0.3
# define RELOAD 100000
# define HUD 96

int					animation(t_mlx *mlx);
void				*bmp_to_img(char *str);
int					colors(t_mlx *mlx, t_img *d, t_all_data *t, int w);
int					doomguy(t_mlx *mlx, clock_t time);
int					error(int i);
int					expose_image(t_mlx *mlx);
int					expose_screen(t_mlx *mlx);
int					freesplit(char **split);
unsigned char		*get_data_from_flux(FILE *flux, t_bmp bmp);
int					get_height(t_mlx *mlx);
int					get_length(t_mlx *mlx, t_ray ray, int w);
int					get_static_numdg(int i);
t_spr				*get_static_gun(t_spr *t);
t_spr				*get_static_dg(t_spr *guy);
char				*get_static_level(char *path);
t_mlx				**get_static_mlx(t_mlx **mlx);
int					get_static_textures(int i);
int					get_static_textureF(int i);
clock_t				get_static_time(clock_t time);
char				*get_texture_color(t_mlx *mlx, int x, int y, t_all_data *t);
int					get_texture_floor(t_mlx *mlx, t_img *d, t_all_data *t, int x);
int					horizon(t_mlx *mlx);
void				*img_from_data(unsigned char *data, t_bmp bmp);
int					Init_level(t_mlx *mlx, char *path);
int					Init_textures(t_mlx *mlx);
int					key_press(int key, t_mlx *mlx);
int					key_release(int key, t_mlx *mlx);
int					key_texture(int key, t_mlx *mlx);
int					move(int key, t_mlx *mlx);
int					raycasting(t_mlx *mlx);
int					refresh(t_mlx *mlx);
int					rotate(int key, t_mlx *mlx);
int					set_image(t_mlx *mlx);

#endif
