/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 14:19:35 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		closewolf(t_mlx *mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
}

int		horizon(t_mlx *mlx)
{
	int	i;
	int	j;

	if (mlx == NULL)
		return (1);
	if ((mlx->horizon = (double *)malloc(sizeof(double) * (SCR_H / 2))) == NULL)
		return (1);
	i = 0;
	j = SCR_H / 2;
	while (i < SCR_H / 2)
	{
		mlx->horizon[i] = SCR_H / (2.0 * j - SCR_H);
		i++;
		j++;
	}
	mlx->horizon[(SCR_H / 2) - 1] = 1.0;
	return (0);
}

int		freesplit(char **split)
{
	int	i;

	if (split == NULL)
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
