/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:30:44 by csellier          #+#    #+#             */
/*   Updated: 2015/12/18 17:26:40 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*s2;

	i = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	if (i > ft_strlen(s) - 1)
		return (ft_strnew(0));
	k = i;
	i = ft_strlen(s) - 1;
	while ((i > k) && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i--;
	s2 = ft_strsub(s, k, i - k + 1);
	return (s2);
}
