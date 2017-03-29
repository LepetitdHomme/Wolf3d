/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		Init_player(t_mlx *mlx)
{
	if (mlx == NULL)
		return (1);
	if ((mlx->player = (t_player *)malloc(sizeof(t_player))) == NULL)
		return (1);
	mlx->player->x = mlx->xstart;
	mlx->player->y = mlx->ystart;
	mlx->player->lookx = 1;
	mlx->player->looky = 0;
	mlx->player->scrx = 0;
	mlx->player->scry = 0.66;
	return (0);
}

static int		Init_static(t_mlx **mlx)
{
	get_static_mlx(mlx);
	get_static_level(NULL);
	get_static_textures(1);
	get_static_textureF(1);
	get_static_time(clock());
	return (0);
}

static int		Init_keys(t_mlx *mlx)
{
	if (mlx == NULL)
		return (1);
	mlx->keys.ll = 0;
	mlx->keys.lr = 0;
	mlx->keys.ml = 0;
	mlx->keys.mr = 0;
	mlx->keys.mf = 0;
	mlx->keys.mb = 0;
	mlx->keys.sp = 0;
	return (0);
}

int				Init_mlx(t_mlx *mlx)
{
	if (Init_level(mlx, get_static_level("maps/lvl1.txt")) != 0)
		return (1);
	if (Init_player(mlx) != 0 || Init_keys(mlx) != 0)
		return (1);
	if ((mlx->scr = mlx_init()) == NULL)
		return (1);
	if ((mlx->win = mlx_new_window(mlx->scr, SCR_W, SCR_H, "Wolf3d")) == NULL ||
	(mlx->dist = (double *)malloc(sizeof(double) * SCR_W)) == NULL ||
	(mlx->height = (int *)malloc(sizeof(int) * SCR_W)) == NULL ||
	(mlx->compass = (int *)malloc(sizeof(int) * SCR_W)) == NULL ||
	(mlx->tool = (t_tool *)malloc(sizeof(t_tool) * SCR_W)) == NULL ||
	(mlx->spr = (t_all_spr *)malloc(sizeof(t_all_spr))) == NULL ||
	(mlx->txt = (t_all_txt *)malloc(sizeof(t_all_txt))) == NULL ||
	horizon(mlx) != 0 || Init_textures(mlx) != 0)
		return (1);
	get_static_gun(&(mlx->spr->sg1));
	get_static_dg(&(mlx->spr->dg));
	get_static_numdg(1);
	mlx->img = NULL;
	return (0);
}

int				main(void)
{
	t_mlx	*mlx;

	if ((mlx = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		return (1);
	if (Init_static(&mlx) != 0)
		return (1);
	if (Init_mlx(mlx) != 0)
		return (1);
	if (expose_image(mlx) != 0)
		return (1);
	mlx_do_key_autorepeaton(mlx->scr);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_expose_hook(mlx->win, expose_screen, mlx);
	mlx_loop_hook(mlx->scr, refresh, mlx);
	mlx_loop(mlx->scr);
	return (0);
}
