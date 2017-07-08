/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/04/03 14:15:57 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	init_bmp(t_bmp *bmp)
{
	bmp->sign = 0;
	bmp->sizefile = 0;
	bmp->reserved1 = 0;
	bmp->offset = 0;
	bmp->sizehead = 0;
	bmp->width = 0;
	bmp->height = 0;
	bmp->plane = 0;
	bmp->bpp = 0;
	bmp->compr = 0;
	bmp->sizeimg = 0;
	bmp->xpermeter = 0;
	bmp->ypermeter = 0;
	bmp->color = 0;
	bmp->fcolor = 0;
	bmp->palette = NULL;
	return (0);
}

static int	header_file(t_bmp *bmp, FILE *flux)
{
	if (flux == NULL)
		return (1);
	fseek(flux, 0L, SEEK_SET);
	if (fread(&bmp->sign, 2, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->sizefile, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->reserved1, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->offset, 4, 1, flux) < 1)
		return (error(1));
	return (0);
}

static int	header_bmp(t_bmp *bmp, FILE *flux)
{
	if (flux == NULL)
		return (1);
	if (fread(&bmp->sizehead, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->width, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->height, 4, 1, flux) < 1)
		return (1);
	if (fread(&bmp->plane, 2, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->bpp, 2, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->compr, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->sizeimg, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->xpermeter, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->ypermeter, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->color, 4, 1, flux) < 1)
		return (error(1));
	if (fread(&bmp->fcolor, 4, 1, flux) < 1)
		return (error(1));
	return (0);
}

static int	palette(t_bmp *bmp, FILE *flux)
{
	int				i;
	int				j;
	unsigned char	tmp;

	if (flux == NULL)
		return (1);
	if ((bmp->palette = (unsigned int *)malloc(sizeof(unsigned int) * 256))
	== NULL)
		return (1);
	i = 0;
	while (i < 256)
	{
		j = 0;
		bmp->palette[i] = 0;
		while (j < 4)
		{
			fread(&tmp, 1, 1, flux);
			bmp->palette[i] += tmp;
			if (j != 3)
				bmp->palette[i] = bmp->palette[i] << 8;
			j++;
		}
		i++;
	}
	return (0);
}

void		*bmp_to_img(char *str)
{
	t_bmp			bmp;
	FILE			*flux;
	unsigned char	*new;

	init_bmp(&bmp);
	if ((flux = fopen(str, "rb")) == NULL && error(0))
		return (NULL);
	if (header_file(&bmp, flux) != 0 && fclose(flux) == 0 && error(1))
		return (NULL);
	if (header_bmp(&bmp, flux) != 0 && fclose(flux) == 0 && error(2))
		return (NULL);
	if (palette(&bmp, flux) != 0 && fclose(flux) == 0 && error(4))
		return (NULL);
	if ((bmp.width < 0 || bmp.height < 0) && fclose(flux) == 0 && error(2))
		return (NULL);
	fseek(flux, bmp.offset, SEEK_SET);
	new = NULL;
	if ((new = get_data_from_flux(flux, bmp)) == NULL &&
	fclose(flux) == 0 && error(3))
		return (NULL);
	fclose(flux);
	return (img_from_data(new, bmp));
}
