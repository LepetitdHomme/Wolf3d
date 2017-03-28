/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:49:39 by csellier          #+#    #+#             */
/*   Updated: 2015/12/18 17:29:07 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_size;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		little_size = ft_strlen((char*)little);
		if (len - i >= little_size && ft_strncmp(big + i, little,
					little_size) == 0)
			return ((char*)(big + i));
		else if (len - i < little_size)
			return (NULL);
		i++;
	}
	return (NULL);
}
