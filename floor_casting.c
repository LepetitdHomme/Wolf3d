/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/19 19:35:08 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double	get_weight(double curD, double playD, double wallD)
{
	return ((curD - playD) / (wallD - playD));
}

static double	pix(double x)
{
	return ((int)(x * UNITE) % UNITE);
}

static int		get_wall(t_mlx *m, int x, double *x2, double *y2)
{
	if (m->tool[x].ray.side == 0)
	{
		if (m->tool[x].ray.lookx > 0)
		{
			*x2 = m->tool[x].ray.gridX;
			*y2 = m->tool[x].ray.gridY + m->tool[x].modulo;
			return (0);
		}
		*x2 = m->tool[x].ray.gridX + 1.0;
		*y2 = m->tool[x].ray.gridY + m->tool[x].modulo;
		return (0);
	}
	if (m->tool[x].ray.looky > 0)
	{
		*x2 = m->tool[x].ray.gridX + m->tool[x].modulo;
		*y2 = m->tool[x].ray.gridY;
		return (0);
	}
	*x2 = m->tool[x].ray.gridX + m->tool[x].modulo;
	*y2 = m->tool[x].ray.gridY + 1.0;
	return (0);
}

static int		fill_data(t_img *d, t_all_data *t, t_floor f, int y)
{
	int	sky;
	int	floor;
	int	tex;

	if (d == NULL || t == NULL)
		return (1);
	sky = (f.x * d->b / 8) + ((SCR_H - y) * d->l);
	floor = (f.x * d->b / 8) + (y * d->l);
	tex = ((int)f.xw * t->F.b / 8) + ((int)f.yw * t->F.l);
	d->d[sky] = t->S.d[tex];
	d->d[sky + 1] = t->S.d[tex + 1];
	d->d[sky + 2] = t->S.d[tex + 2];
	d->d[sky + 3] = t->S.d[tex + 3];
	d->d[floor] = t->F.d[tex];
	d->d[floor + 1] = t->F.d[tex + 1];
	d->d[floor + 2] = t->F.d[tex + 2];
	d->d[floor + 3] = t->F.d[tex + 3];
	return (0);
}
int				get_texture_floor(t_mlx *mlx, t_img *d, t_all_data *t, int x)
{
	t_floor	f;
	int		y = SCR_H / 2 + mlx->height[x] / 2;

	get_wall(mlx, x, &f.xstart, &f.ystart);
	f.x = x;
	while (y < SCR_H)
	{
		f.p = get_weight(mlx->horizon[y - (SCR_H / 2)], 0, mlx->dist[x]);
		f.xw = f.p * f.xstart + (1.0 - f.p) * mlx->player->x;
		f.yw = f.p * f.ystart + (1.0 - f.p) * mlx->player->y;
		f.xw = (int)pix(f.xw);
		f.yw = (int)pix(f.yw);
		fill_data(d, t, f, y);
		y++;
	}
	return (0);
}

