/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/08 23:17:19 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	fill_image(t_mlx *mlx, t_img *d, t_all_data *t)
{
	int		w;

	if (mlx == NULL || d == NULL || t == NULL)
		return (1);
	w = 0;
	while (w < SCR_W)
	{
		if (colors(mlx, d, t, w) != 0)
			return (1);
		w++;
	}
	return (0);
}

static int	get_data(void	*s, t_img *img)
{
	if (s == NULL || img == NULL)
		return (1);
	if ((img->d = mlx_get_data_addr(s, &img->b, &img->l, &img->e)) == NULL)
		return (1);
	return (0);
}

int			set_image(t_mlx *m)
{
	t_img		d;
	t_all_data	t;

	if (m->img != NULL)
		mlx_destroy_image(m->scr, m->img);
	if ((m->img = mlx_new_image(m->scr, SCR_W, SCR_H)) == NULL)
		return (1);
	if (get_data(m->img, &d) != 0 || get_data(m->txt->w, &t.w) != 0 ||
	get_data(m->txt->w2, &t.w2) != 0 || get_data(m->txt->w3, &t.w3) != 0 ||
	get_data(m->txt->w4, &t.w4) != 0 || get_data(m->txt->w5, &t.w5) != 0 ||
	get_data(m->txt->w6, &t.w6) != 0 || get_data(m->txt->D, &t.D) != 0 ||
	get_data(m->txt->F, &t.F) != 0 || get_data(m->txt->S, &t.S) != 0)
		return (1);
	if (fill_image(m, &d, &t) != 0)
		return (1);
	return (0);
}
