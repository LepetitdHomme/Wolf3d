/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 14:16:02 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		s(t_bmp bmp)
{
	return (bmp.width * bmp.height);
}

static int		set_data(unsigned char *data, t_bmp bmp)
{
	int	i;

	i = 0;
	while (i < s(bmp))
		data[i++] = 0;
	return (0);
}

unsigned char	*get_data_from_flux(FILE *flux, t_bmp bmp)
{
	unsigned char	*ret;
	int				h;
	int				w;
	int				i;

	if ((ret = (unsigned char *)malloc(sizeof(unsigned char) * s(bmp))) == NULL)
		return (NULL);
	i = 0;
	h = 0;
	set_data(ret, bmp);
	fseek(flux, bmp.offset, SEEK_SET);
	while (h < bmp.height)
	{
		w = 0;
		while (w < bmp.width)
		{
			fread(&ret[i++], sizeof(unsigned char), 1, flux);
			w++;
		}
		if (w % 4 != 0)
			if (fread(NULL, w % 4, 1, flux) < 1)
				error(3);
		h++;
	}
	return (ret);
}
