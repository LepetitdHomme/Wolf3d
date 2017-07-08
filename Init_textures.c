/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 13:45:40 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			key_texture(int key, t_mlx *mlx)
{
	if (key == KEY_TXT)
	{
		get_static_textures(-1) == 1 ? get_static_textures(0) :
		get_static_textures(1);
	}
	else if (key == KEY_TXTF)
	{
		get_static_texturef(-1) == 1 ? get_static_texturef(0) :
		get_static_texturef(1);
	}
	set_image(mlx);
	return (expose_screen(mlx));
}

static int	load_txt_walls(t_mlx *mlx)
{
	if ((mlx->txt->w = bmp_to_img("textures/wall/Slime5.bmp")) == NULL ||
	(mlx->txt->w2 = bmp_to_img("textures/wall/Slime6.bmp")) == NULL ||
	(mlx->txt->w3 = bmp_to_img("textures/wall/Grey2.bmp")) == NULL ||
	(mlx->txt->w4 = bmp_to_img("textures/wall/Black1.bmp")) == NULL ||
	(mlx->txt->w5 = bmp_to_img("textures/wall/Stone7.bmp")) == NULL ||
	(mlx->txt->w6 = bmp_to_img("textures/wall/Stone5.bmp")) == NULL ||
	(mlx->txt->d = bmp_to_img("textures/wall/Door5.bmp")) == NULL ||
	(mlx->txt->f = bmp_to_img("textures/wall/FLOOR.bmp")) == NULL ||
	(mlx->txt->s = bmp_to_img("textures/wall/SKY.bmp")) == NULL)
		return (1);
	return (0);
}

static int	x(t_mlx *m, t_spr *d, char *path)
{
	if ((d->d = mlx_xpm_file_to_image(m->scr, path, &(d->w), &(d->h))) == NULL)
		return (1);
	return (0);
}

static int	load_txt_gun(t_mlx *m)
{
	if (x(m, &m->spr->sg1, "textures/shotg/sg.xpm") != 0 ||
	x(m, &m->spr->sg2, "textures/shotg/sg2.xpm") != 0 ||
	x(m, &m->spr->sg3, "textures/shotg/sg3.xpm") != 0 ||
	x(m, &m->spr->sg4, "textures/shotg/sg4.xpm") != 0 ||
	x(m, &m->spr->sg5, "textures/shotg/sg5.xpm") != 0 ||
	x(m, &m->spr->sg6, "textures/shotg/sg6.xpm") != 0 ||
	x(m, &m->spr->sg7, "textures/shotg/sg7.xpm") != 0 ||
	x(m, &m->spr->sg8, "textures/shotg/sg8.xpm") != 0 ||
	x(m, &m->spr->sg9, "textures/shotg/sg9.xpm") != 0 ||
	x(m, &m->spr->sg10, "textures/shotg/sg10.xpm") != 0 ||
	x(m, &m->spr->sg11, "textures/shotg/sg11.xpm") != 0 ||
	x(m, &m->spr->dg, "textures/HUD/dg.xpm") != 0 ||
	x(m, &m->spr->dg2, "textures/HUD/dg2.xpm") != 0 ||
	x(m, &m->spr->dg3, "textures/HUD/dg3.xpm") != 0 ||
	x(m, &m->spr->hud, "textures/HUD/fond.xpm") != 0)
		return (1);
	return (0);
}

int			init_textures(t_mlx *mlx)
{
	if (mlx == NULL)
		return (1);
	if (load_txt_walls(mlx) != 0)
		return (1);
	if (load_txt_gun(mlx) != 0)
		return (1);
	return (0);
}
