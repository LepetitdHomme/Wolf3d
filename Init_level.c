/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/03/27 15:24:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char	**get_split(t_mlx *mlx, int fd)
{
	char	**split;
	char	*buf;

	split = NULL;
	buf = NULL;
	(void)mlx;
	get_next_line(fd, &buf);
	if ((split = ft_strsplit(buf, ' ')) == NULL)
		return (NULL);
	free(buf);
	return (split);
}

static int	get_lvl(t_mlx *mlx, int fd)
{
	int		x;
	int		y;
	char	**split;

	if (mlx == NULL)
		return (1);
	if ((mlx->level = (int **)malloc(sizeof(int *) * mlx->lvl_h)) == NULL)
		return (1);
	y = 0;
	while (y < mlx->lvl_h)
	{
		if ((mlx->level[y] = (int *)malloc(sizeof(int) * mlx->lvl_w)) == NULL)
			return (1);
		x = 0;
		if ((split = get_split(mlx, fd)) == NULL)
			return (1);
		while (x < mlx->lvl_w)
		{
			mlx->level[y][x] = ft_atoi(split[x]);
			x++;
		}
		freesplit(split);
		y++;
	}
	return (0);
}

int			Init_level(t_mlx *mlx, char *str)
{
	int		fd;
	char	*buf;

	if (mlx == NULL || str == NULL)
		return (1);
	if ((fd = open(str, O_RDONLY)) == -1)
		return (1);
	get_next_line(fd, &buf);
	mlx->lvl_w = ft_atoi(buf);
	free(buf);
	get_next_line(fd, &buf);
	mlx->lvl_h = ft_atoi(buf);
	free(buf);
	if (mlx->lvl_h > 99 || mlx->lvl_w > 99)
		return (1);
	get_next_line(fd, &buf);
	mlx->xstart = ft_atoi(buf);
	free(buf);
	get_next_line(fd, &buf);
	mlx->ystart = ft_atoi(buf);
	free(buf);
	if (get_lvl(mlx, fd) == 1)
		return (1);
	close(fd);
	return (0);
}
