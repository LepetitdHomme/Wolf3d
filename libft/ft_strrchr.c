/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:16:53 by csellier          #+#    #+#             */
/*   Updated: 2015/12/17 18:06:21 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;

	i = 0;
	k = -1;
	if ((char)c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)(s + i));
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			k = i;
		i++;
	}
	if (k == -1)
		return (NULL);
	return ((char *)(s + k));
}
