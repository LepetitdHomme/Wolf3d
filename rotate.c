/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		rotate(int key, t_mlx *mlx)
{
	double	a;
	double	tmp;

	if (mlx == NULL)
		return (1);
	a = (key == LOOK_LEFT) ? -ROT : ROT;
	tmp = mlx->player->lookx;
	mlx->player->lookx = (mlx->player->lookx * cos(a)) - (mlx->player->looky * sin(a));
	mlx->player->looky = (tmp * sin(a)) + (mlx->player->looky * cos(a));
	tmp = mlx->player->scrx;
	mlx->player->scrx = mlx->player->scrx * cos(a) - mlx->player->scry * sin(a);
	mlx->player->scry = tmp * sin(a) + mlx->player->scry * cos(a);
	return (0);
}
