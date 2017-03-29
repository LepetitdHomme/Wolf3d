/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == LOOK_LEFT)
		mlx->keys.ll = 1;
	if (key == LOOK_RIGHT)
		mlx->keys.lr = 1;
	if (key == MOVE_FORWARD)
		mlx->keys.mf = 1;
	if (key == MOVE_BACKWARD)
		mlx->keys.mb = 1;
	if (key == MOVE_LEFT)
		mlx->keys.ml = 1;
	if (key == MOVE_RIGHT)
		mlx->keys.mr = 1;
	if (key == SPACE && mlx->keys.sp == 0)
		animation(mlx);
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == LOOK_LEFT)
		mlx->keys.ll = 0;
	if (key == LOOK_RIGHT)
		mlx->keys.lr = 0;
	if (key == MOVE_FORWARD)
		mlx->keys.mf = 0;
	if (key == MOVE_BACKWARD)
		mlx->keys.mb = 0;
	if (key == MOVE_LEFT)
		mlx->keys.ml = 0;
	if (key == MOVE_RIGHT)
		mlx->keys.mr = 0;
	if (key == KEY_TXT || key == KEY_TXTF)
		return (key_texture(key, mlx));
	return (0);
}

int		refresh(t_mlx *mlx)
{
	int	refresh;

	refresh = 0;
	if (mlx->keys.ll == 1 && (refresh = 1))
		rotate(LOOK_LEFT, mlx);
	if (mlx->keys.lr == 1 && (refresh = 1))
		rotate(LOOK_RIGHT, mlx);
	if (mlx->keys.mf == 1 && (refresh = 1))
		move(MOVE_FORWARD, mlx);
	if (mlx->keys.mb == 1 && (refresh = 1))
		move(MOVE_BACKWARD, mlx);
	if (mlx->keys.ml == 1 && (refresh = 1))
		move(MOVE_LEFT, mlx);
	if (mlx->keys.mr == 1 && (refresh = 1))
		move(MOVE_RIGHT, mlx);
	if (doomguy(mlx, clock()) == 0)
		refresh = 1;
	if (mlx->keys.sp == 1)
		refresh = 1;
	if (refresh == 1)
		expose_image(mlx);
	return (0);
}
