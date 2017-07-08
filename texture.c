/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 13:50:41 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	which_tx(t_all_data *t, t_img **a, t_mlx *mlx, int x2)
{
	int		x;
	int		y;

	y = mlx->tool[x2].ray.gridy;
	x = mlx->tool[x2].ray.gridx;
	if (mlx->level[y][x] == 1)
		*a = &t->w;
	else if (mlx->level[y][x] == 2)
		*a = &t->w2;
	else if (mlx->level[y][x] == 3)
		*a = &t->w3;
	else if (mlx->level[y][x] == 4)
		*a = &t->w4;
	else if (mlx->level[y][x] == 5)
		*a = &t->d;
	else if (mlx->level[y][x] == 6)
		*a = &t->w5;
	else if (mlx->level[y][x] == 7)
		*a = &t->w6;
	else
		*a = &t->w;
	return (1);
}

char		*get_texture_color(t_mlx *mlx, int x, int y, t_all_data *t)
{
	int			x2;
	int			y2;
	t_img		*a;

	y2 = (y - ((SCR_H / 2) - mlx->height[x] / 2)) * UNITE;
	y2 /= mlx->height[x];
	x2 = (int)(mlx->tool[x].modulo * (double)UNITE);
	if (mlx->compass[x] == 1 || mlx->compass[x] == 2)
		x2 = UNITE - x2 - 1;
	x2 = x2 * (t->w.b / 8);
	y2 *= t->w.l;
	if (which_tx(t, &a, mlx, x) == 0)
		return (NULL);
	return (&a->d[(int)x2 + (int)y2]);
}
