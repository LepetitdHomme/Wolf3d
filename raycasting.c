/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 13:49:57 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	init_delta(t_mlx *mlx, t_ray *ray)
{
	if (mlx == NULL || ray == NULL)
		return (1);
	if (ray->lookx < 0)
	{
		ray->stepx = -1;
		ray->fsidex = (ray->x - ray->gridx) * ray->dx;
	}
	else
	{
		ray->stepx = 1;
		ray->fsidex = (ray->gridx + 1.0 - ray->x) * ray->dx;
	}
	if (ray->looky < 0)
	{
		ray->stepy = -1;
		ray->fsidey = (ray->y - ray->gridy) * ray->dy;
	}
	else
	{
		ray->stepy = 1;
		ray->fsidey = (ray->gridy + 1.0 - ray->y) * ray->dy;
	}
	return (0);
}

static int	init_ray(t_mlx *mlx, t_ray *ray, int w)
{
	ray->camx = 2 * w / (double)SCR_W - 1;
	ray->x = mlx->player->x;
	ray->y = mlx->player->y;
	ray->lookx = mlx->player->lookx + mlx->player->scrx * ray->camx;
	ray->looky = mlx->player->looky + mlx->player->scry * ray->camx;
	ray->gridx = (int)ray->x;
	ray->gridy = (int)ray->y;
	ray->dx = sqrt(1 + (ray->looky * ray->looky) / (ray->lookx * ray->lookx));
	ray->dy = sqrt(1 + (ray->lookx * ray->lookx) / (ray->looky * ray->looky));
	ray->touche = 0;
	if (init_delta(mlx, ray) != 0)
		return (1);
	return (0);
}

int			raycasting(t_mlx *mlx, int w)
{
	t_ray	ray;

	while (++w < SCR_W)
	{
		if (init_ray(mlx, &ray, w) != 0)
			return (1);
		while (ray.touche == 0)
		{
			if (ray.fsidex < ray.fsidey)
			{
				ray.fsidex += ray.dx;
				ray.gridx += ray.stepx;
				ray.side = 0;
			}
			else
			{
				ray.fsidey += ray.dy;
				ray.gridy += ray.stepy;
				ray.side = 1;
			}
			ray.touche = (mlx->level[ray.gridy][ray.gridx] > 0) ? 1 : 0;
		}
		get_length(mlx, ray, w);
	}
	return (0);
}
