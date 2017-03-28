/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:49:23 by csellier          #+#    #+#             */
/*   Updated: 2016/06/09 16:46:32 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_split(char **split)
{
	int		i;
	char	**copy;
	int		count;

	i = 0;
	if (split == NULL)
		return (NULL);
	if ((count = count_split(split)) <= 0)
		return (NULL);
	if ((copy = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (NULL);
	copy[count] = NULL;
	while (i < count)
	{
		copy[i] = ft_strdup(split[i]);
		i++;
	}
	return (copy);
}
