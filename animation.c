/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/13 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	retour(t_mlx *mlx)
{
	get_static_gun(&mlx->spr->sg6);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg7);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg8);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg9);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg10);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg11);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg1);
	usleep(RELOAD);
	return (0);
}

static int	aller(t_mlx *mlx)
{
	get_static_gun(&mlx->spr->sg2);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg3);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg4);
	usleep(RELOAD);
	get_static_gun(&mlx->spr->sg5);
	usleep(RELOAD);
	return (0);
}

static void	*change_gun(void *data)
{
	t_mlx	*mlx;

	mlx = *get_static_mlx(NULL);
	aller(mlx);
	retour(mlx);
	mlx->keys.sp = 0;
	pthread_exit(NULL);
	return (data);
}

int			animation(t_mlx *mlx)
{
	pthread_t	thread[1];

	if (mlx == NULL)
		mlx = *get_static_mlx(NULL);
	mlx->keys.sp = 1;
	pthread_create(&thread[0], NULL, change_gun, NULL);
	return (0);
}
