/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	put_sprites(t_mlx *m)
{
	t_spr	*d;

	if ((d = get_static_gun(NULL)) == NULL)
	{
		DEBUG;
		return (1);
	}
	mlx_put_image_to_window(m->scr, m->win, d->d, SCR_W / 2 - d->w / 2, SCR_H -
	HUD - d->h);
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
	mlx_put_image_to_window(mlx->scr, mlx->win, mlx->img, 0, 0);
	put_sprites(mlx);
	return (0);
}
