/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:37:22 by csellier          #+#    #+#             */
/*   Updated: 2016/01/15 18:38:57 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri(const char *s, int c)
{
	int i;

	i = -1;
	if ((char)c == '\0')
		return (ft_strlen((const char *)s));
	while (s[++i] != '\0')
	{
		if ((char)c == s[i])
			return (i);
	}
	return (-1);
}
