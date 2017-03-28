/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_height(t_mlx *mlx)
{
	int	w;

	if (mlx == NULL || mlx->dist == NULL || mlx->height == NULL)
		return (1);
	w = 0;
	while (w < SCR_W)
	{
		mlx->height[w] = (int)(SCR_H / mlx->dist[w]);
		w++;
	}
	return (0);
}

static int	fill_tool(t_mlx *mlx, t_ray ray, int w)
{
	if (mlx == NULL)
		return (1);
	mlx->tool[w].ray = ray;
	if (ray.side == 0)
		mlx->tool[w].modulo = ray.y + mlx->dist[w] * ray.looky;
	else
		mlx->tool[w].modulo = ray.x + mlx->dist[w] * ray.lookx;
	mlx->tool[w].modulo -= floor(mlx->tool[w].modulo);
	return (0);
}

int			get_length(t_mlx *mlx, t_ray ray, int w)
{
	if (mlx == NULL || mlx->dist == NULL)
		return (1);
	if (ray.side == 0)
		mlx->dist[w] = (ray.gridX - ray.x + (1 - ray.stepX) / 2) / ray.lookx;
	else
		mlx->dist[w] = (ray.gridY - ray.y + (1 - ray.stepY) / 2) / ray.looky;
	if (fill_tool(mlx, ray, w) != 0)
		return (1);
	if (ray.side == 0)
		mlx->compass[w] = (ray.lookx > 0) ? 1 : 3;
	else
		mlx->compass[w] = (ray.looky > 0) ? 0 : 2;
	return (0);
}
