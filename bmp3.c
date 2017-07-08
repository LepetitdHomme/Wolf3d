/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 14:16:10 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		set_img(t_img ndata, unsigned char *data, t_bmp bmp)
{
	int		y;
	int		x;
	int		k;
	int		index;

	y = 0;
	while (y < bmp.height)
	{
		x = 0;
		k = (bmp.height - 1 - y) * bmp.width;
		while (x < bmp.width)
		{
			index = (x * ndata.b / 8) + (y * ndata.l);
			ndata.d[index] = (bmp.palette[data[k]] >> 24) & 0xFF;
			ndata.d[index + 1] = (bmp.palette[data[k]] >> 16) & 0xFF;
			ndata.d[index + 2] = (bmp.palette[data[k]] >> 8) & 0xFF;
			ndata.d[index + 3] = bmp.palette[data[k]] & 0xFF;
			k++;
			x++;
		}
		y++;
	}
}

static void		get_image(unsigned char *data, t_bmp bmp, void *img)
{
	t_img	ndata;

	if (data == NULL)
		return ;
	ndata.d = mlx_get_data_addr(img, &ndata.b, &ndata.l, &ndata.e);
	set_img(ndata, data, bmp);
}

void			*img_from_data(unsigned char *data, t_bmp b)
{
	void	*img;
	t_mlx	*x;

	if (data == NULL)
		return (NULL);
	x = *get_static_mlx(NULL);
	if ((img = mlx_new_image(x->scr, b.width, b.height)) == NULL)
	{
		free(b.palette);
		return (NULL);
	}
	get_image(data, b, img);
	free(data);
	free(b.palette);
	return (img);
}
