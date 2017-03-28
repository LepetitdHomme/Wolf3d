/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 11:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_spr	*get_static_gun(t_spr *gun)
{
	static t_spr	*t = NULL;

	if (gun != NULL)
		t = gun;
	return (t);
}

int		get_static_textureF(int i)
{
	static int	txt = 1;

	if (i != -1)
		txt = i;
	return (txt);
}

int		get_static_textures(int i)
{
	static int	txt = 1;

	if (i != -1)
		txt = i;
	return (txt);
}

t_mlx	**get_static_mlx(t_mlx **source)
{
	static t_mlx	**mlx = NULL;

	if (source != NULL)
		mlx = source;
	return (mlx);
}

char	*get_static_level(char *path)
{
	static char	*lvl = NULL;

	if (path != NULL)
	{
		if (lvl != NULL)
			free(lvl);
		lvl = ft_strdup(path);
	}
	return (lvl);
}
