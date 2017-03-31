/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/31 08:58:59 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

clock_t	get_static_time(clock_t new)
{
	static clock_t old = 0;

	if (new != 0)
		old = new;
	return (old);
}

t_spr	*get_static_dg(t_spr *guy)
{
	static t_spr	*dg = NULL;

	if (guy != NULL)
		dg = guy;
	return (dg);
}

int		get_static_numdg(int i)
{
	static int	dg = 1;

	if (i != -1)
		dg = i;
	return (dg);
}
