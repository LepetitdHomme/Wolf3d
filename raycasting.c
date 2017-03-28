/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	Init_delta(t_mlx *mlx, t_ray *ray)
{
	if (mlx == NULL || ray == NULL)
		return (1);
	if (ray->lookx < 0)
	{
		ray->stepX = -1;
		ray->FsideX = (ray->x - ray->gridX) * ray->dx;
	}
	else
	{
		ray->stepX = 1;
		ray->FsideX = (ray->gridX + 1.0 - ray->x) * ray->dx;
	}
	if (ray->looky < 0)
	{
		ray->stepY = -1;
		ray->FsideY = (ray->y - ray->gridY) * ray->dy;
	}
	else
	{
		ray->stepY = 1;
		ray->FsideY = (ray->gridY + 1.0 - ray->y) * ray->dy;
	}
	return (0);
}

static int	Init_ray(t_mlx *mlx, t_ray *ray, int w)
{
	ray->camX = 2 * w / (double)SCR_W - 1;
	ray->x = mlx->player->x;
	ray->y = mlx->player->y;
	ray->lookx = mlx->player->lookx + mlx->player->scrx * ray->camX;
	ray->looky = mlx->player->looky + mlx->player->scry * ray->camX;
	ray->gridX = (int)ray->x;
	ray->gridY = (int)ray->y;
	ray->dx = sqrt(1 + (ray->looky * ray->looky) / (ray->lookx * ray->lookx));
	ray->dy = sqrt(1 + (ray->lookx * ray->lookx) / (ray->looky * ray->looky));
	ray->touche = 0;
	if (Init_delta(mlx, ray) != 0)
		return (1);
	return (0);
}

int		raycasting(t_mlx *mlx)
{
	int		w;
	t_ray	ray;

	w = 0;
	while (w < SCR_W)
	{
		if (Init_ray(mlx, &ray, w) != 0)
			return (1);
		while (ray.touche == 0)
		{
			if (ray.FsideX < ray.FsideY)
			{
				ray.FsideX += ray.dx;
				ray.gridX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.FsideY += ray.dy;
				ray.gridY += ray.stepY;
				ray.side = 1;
			}
			ray.touche = (mlx->level[ray.gridY][ray.gridX] > 0) ? 1 : 0;
		}
		get_length(mlx, ray, w);
		w++;
	}
	return (0);
}
