/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/31 09:08:38 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	do_sky(t_mlx *mlx, t_img *d, int x, int y)
{
	int	z;

	if (mlx == NULL)
		return (1);
	z = (x * d->b / 8) + (y * d->l);
	d->d[z] = 241;
	d->d[z + 1] = 208;
	d->d[z + 2] = 116;
	d->d[z + 3] = 116;
	return (0);
}

static int	do_walls(t_img *d, t_all_data *t, int x, int y)
{
	int		z;
	t_mlx	*mlx;
	char	*ztxt;

	mlx = *get_static_mlx(NULL);
	z = (x * d->b / 8) + (y * d->l);
	ztxt = NULL;
	if (get_static_textures(-1) == 0)
	{
		if ((ztxt = get_texture_color(mlx, x, y, t)) == NULL)
			return (1);
		d->d[z] = *ztxt;
		d->d[z + 1] = *(ztxt + 1);
		d->d[z + 2] = *(ztxt + 2);
		d->d[z + 3] = *(ztxt + 3);
		return (0);
	}
	d->d[z] = (mlx->compass[x] == 0) ? 255 : 0;
	d->d[z + 1] = (mlx->compass[x] == 1) ? 255 : 0;
	d->d[z + 2] = (mlx->compass[x] == 2) ? 255 : 127;
	d->d[z + 3] = 255;
	return (0);
}

static int	do_floor(t_mlx *mlx, t_img *d, int x, int y)
{
	int	z;

	(void)mlx;
	z = (x * d->b / 8) + (y * d->l);
	d->d[z] = 63;
	d->d[z + 1] = 63;
	d->d[z + 2] = 63;
	d->d[z + 3] = 63;
	return (0);
}

int			colors(t_mlx *mlx, t_img *d, t_all_data *t, int w)
{
	int	h;
	int	top;
	int	down;

	if (mlx == NULL || d == NULL || t == NULL)
		return (1);
	h = 0;
	top = SCR_H / 2 - mlx->height[w] / 2;
	down = SCR_H / 2 + mlx->height[w] / 2;
	while (h < SCR_H)
	{
		if (h < top && h >= HUD && get_static_textureF(-1) != 0)
			do_sky(mlx, d, w, h);
		else if (h >= top && h < down && h >= HUD && h < SCR_H - HUD)
			do_walls(d, t, w, h);
		else if (h >= down && h < SCR_H - HUD && get_static_textureF(-1) != 0)
			do_floor(mlx, d, w, h);
		else if (h >= down && h < SCR_H && get_static_textureF(-1) == 0)
		{
			get_texture_floor(mlx, d, t, w);
			break ;
		}
		h++;
	}
	return (0);
}
