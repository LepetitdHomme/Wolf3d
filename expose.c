/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/27 22:09:52 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	putimg(t_mlx *m, t_spr *spr, int i)
{
	int	h;

	if (m == NULL)
		return (1);
	if (i == 0)
		h = SCR_H - HUD - spr->h;
	else
		h = (i == 1) ? SCR_H - (HUD) : SCR_H - (HUD - 8);
	mlx_put_image_to_window(m->scr, m->win, spr->d, SCR_W / 2 - spr->w / 2, h);
	return (0);
}

static int	put_sprites(t_mlx *m)
{
	t_spr	*d;
	t_spr	*dg;

	if ((d = get_static_gun(NULL)) == NULL)
		return (1);
	if ((dg = get_static_dg(NULL)) == NULL)
		return (1);
	putimg(m, d, 0);
	putimg(m, dg, 2);
	return (0);
}

int			expose_screen(t_mlx *mlx)
{
	if (mlx->img != NULL)
	{
		mlx_put_image_to_window(mlx->scr, mlx->win, mlx->img, 0, 0);
		put_sprites(mlx);
		return (0);
	}
	expose_image(mlx);
	return (0);
}

static int	reset_tabs(t_mlx *mlx)
{
	if (mlx == NULL)
		return (1);
	if (mlx->dist != NULL)
		free(mlx->dist);
	if ((mlx->dist = (double *)malloc(sizeof(double) * SCR_W)) == NULL)
			return (1);
	if (mlx->height != NULL)
		free(mlx->height);
	if ((mlx->height = (int *)malloc(sizeof(int) * SCR_W)) == NULL)
		return (1);
	if (mlx->compass != NULL)
		free(mlx->compass);
	if ((mlx->compass = (int *)malloc(sizeof(int) * SCR_W)) == NULL)
		return (1);
	if (mlx->tool != NULL)
		free(mlx->tool);
	if ((mlx->tool = (t_tool *)malloc(sizeof(t_tool) * SCR_W)) == NULL)
		return (1);
	return (0);
}

int			expose_image(t_mlx *mlx)
{
	if (reset_tabs(mlx) != 0)
		return (1);
	if (raycasting(mlx) != 0)
		return (1);
	if (get_height(mlx) != 0)
		return (1);
	if (set_image(mlx) != 0)
		return (1);
//	mlx_clear_window(mlx->scr, mlx->win);
	mlx_put_image_to_window(mlx->scr, mlx->win, mlx->img, 0, 0);
	put_sprites(mlx);
	return (0);
}
