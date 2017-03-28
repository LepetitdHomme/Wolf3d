/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:53:12 by csellier          #+#    #+#             */
/*   Updated: 2015/12/15 18:21:42 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	d = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == d)
		{
			s1[i] = s2[i];
			i++;
			return ((dst + i));
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
