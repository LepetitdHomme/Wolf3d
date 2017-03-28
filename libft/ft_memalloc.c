/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:26:04 by csellier          #+#    #+#             */
/*   Updated: 2015/12/11 17:02:26 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = (void *)malloc(sizeof(p) * size);
	if (p == NULL)
		return (NULL);
	while (i < size)
	{
		((int *)p)[i] = 0;
		i++;
	}
	return ((void *)p);
}
