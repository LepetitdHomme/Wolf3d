/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 14:10:46 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	check_in_grid(t_mlx *m, double z, int i)
{
	if (i == 0 && (int)z >= 0 && (int)z < m->lvl_h)
		return (0);
	if (i == 1 && (int)z >= 0 && (int)z < m->lvl_w)
		return (0);
	return (1);
}

static int	lateral(int key, t_mlx *m)
{
	double	dirx;
	double	diry;
	double	a;
	double	test;

	a = (key == MOVE_LEFT) ? -ANGLE : ANGLE;
	test = SPEED * 1.25;
	dirx = m->player->lookx * cos(a) - (m->player->looky * sin(a));
	diry = m->player->lookx * sin(a) + (m->player->looky * cos(a));
	if (check_in_grid(m, m->player->x + dirx * test, 1) == 0 &&
	m->level[(int)m->player->y][(int)(m->player->x + dirx * test)] == 0)
		m->player->x += dirx * SPEED;
	if (check_in_grid(m, m->player->y + diry * test, 0) == 0 &&
	m->level[(int)(m->player->y + diry * test)][(int)m->player->x] == 0)
		m->player->y += diry * SPEED;
	return (0);
}

static int	check_forw(t_mlx *m, double test)
{
	if (check_in_grid(m, m->player->x + m->player->lookx * test, 1) == 0 &&
			check_in_grid(m, m->player->x + m->player->lookx * SPEED, 1)
			== 0 && m->level[(int)m->player->y]
			[(int)(m->player->x + m->player->lookx * test)] == 0)
		m->player->x += m->player->lookx * SPEED;
	if (check_in_grid(m, m->player->y + m->player->looky * test, 0) == 0 &&
			check_in_grid(m, m->player->y + m->player->looky * SPEED, 0)
			== 0 && m->level[(int)(m->player->y + m->player->looky * test)]
			[(int)m->player->x] == 0)
		m->player->y += m->player->looky * SPEED;
	return (0);
}

static int	check_back(t_mlx *m, double test)
{
	if (check_in_grid(m, m->player->x - m->player->lookx * test, 1) == 0 &&
			check_in_grid(m, m->player->x - m->player->lookx * SPEED, 1)
			== 0 && m->level[(int)m->player->y]
			[(int)(m->player->x - m->player->lookx * test)] == 0)
		m->player->x -= m->player->lookx * SPEED;
	if (check_in_grid(m, m->player->y - m->player->looky * test, 0) == 0 &&
			check_in_grid(m, m->player->y - m->player->looky * SPEED, 0)
			== 0 && m->level[(int)(m->player->y - m->player->looky * test)]
			[(int)m->player->x] == 0)
		m->player->y -= m->player->looky * SPEED;
	return (0);
}

int			move(int key, t_mlx *m)
{
	double	test;

	if (m == NULL)
		return (1);
	test = SPEED * 1.25;
	if (key == MOVE_FORWARD)
		check_forw(m, test);
	if (key == MOVE_BACKWARD)
		check_back(m, test);
	if (key == MOVE_LEFT || key == MOVE_RIGHT)
		lateral(key, m);
	return (0);
}
