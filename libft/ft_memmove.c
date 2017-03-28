/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:05:53 by csellier          #+#    #+#             */
/*   Updated: 2015/12/17 10:06:52 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (len > 0)
	{
		if (s2 < s1)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
		else
		{
			s1[i] = s2[i];
			i++;
			len--;
		}
	}
	return (s1);
}
