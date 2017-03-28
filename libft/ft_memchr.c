/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:13:12 by csellier          #+#    #+#             */
/*   Updated: 2015/12/15 18:21:30 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == d)
			return ((void *)(s2 + i));
		i++;
	}
	return (NULL);
}
