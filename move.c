/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	lateral(int key, t_mlx *m)
{
	double	dirx;
	double	diry;
	double	a;

	a = (key == MOVE_LEFT) ? -ANGLE : ANGLE;
	dirx = m->player->lookx * cos(a) - (m->player->looky * sin(a));
	diry = m->player->lookx * sin(a) + (m->player->looky * cos(a));
	if (m->level[(int)m->player->y][(int)(m->player->x + dirx * 0.75)] == 0)
		m->player->x += dirx * SPEED;
	if (m->level[(int)(m->player->y + diry * 0.75)][(int)m->player->x] == 0)
		m->player->y += diry * SPEED;
	return (0);
}


int			move(int key, t_mlx *m)
{
	double	test;

	if (m == NULL)
		return (1);
	test = 0.75;
	if (key == MOVE_FORWARD)
	{
		if (m->level[(int)m->player->y][(int)(m->player->x + m->player->lookx * test)] == 0)
			m->player->x += m->player->lookx * SPEED;
		if (m->level[(int)(m->player->y + m->player->looky * test)][(int)m->player->x] == 0)
			m->player->y += m->player->looky * SPEED;
	}
	if (key == MOVE_BACKWARD)
	{
		if (m->level[(int)m->player->y][(int)(m->player->x - m->player->lookx * test)] == 0)
			m->player->x -= m->player->lookx * SPEED;
		if (m->level[(int)(m->player->y - m->player->looky * test)][(int)m->player->x] == 0)
			m->player->y -= m->player->looky * SPEED;
	}
	if (key == MOVE_LEFT || key == MOVE_RIGHT)
		lateral(key, m);
	return (0);
}
