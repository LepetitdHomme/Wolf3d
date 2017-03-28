/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:22:32 by csellier          #+#    #+#             */
/*   Updated: 2015/12/15 17:26:48 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	k = ft_strlen((char *)little);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = (ft_strncmp((char *)(big + i), little, (size_t)k));
		if (j == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
