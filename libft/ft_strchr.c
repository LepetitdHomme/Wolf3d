/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:01:14 by csellier          #+#    #+#             */
/*   Updated: 2015/12/15 18:59:16 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)(s + i));
	}
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
