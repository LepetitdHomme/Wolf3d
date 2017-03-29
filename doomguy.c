/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doomguy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	swap_dg(t_mlx *mlx, int i)
{
	if (i == 1)
		get_static_dg(&mlx->spr->dg);
	else if (i == 2 || i == 3)
		get_static_dg(&mlx->spr->dg2);
	else
		get_static_dg(&mlx->spr->dg3);
	return (0);
}

static int	swap_numdg(void)
{
	int	dg;

	dg = get_static_numdg(-1);
	if (dg == 1)
		dg = 3;
	else if (dg == 2)
		dg = 1;
	else if (dg == 3)
		dg = 4;
	else
		dg = 2;
	get_static_numdg(dg);
	return (0);
}

int			doomguy(t_mlx *m, clock_t new)
{
	clock_t	old;

	old = get_static_time(-1);
	if (abs(old / CLOCKS_PER_SEC - new / CLOCKS_PER_SEC) < 1)
		return (1);
	get_static_time(new);
	swap_numdg();
	swap_dg(m, get_static_numdg(-1));
	return (0);
}

