/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:36:22 by csellier          #+#    #+#             */
/*   Updated: 2016/11/22 13:52:13 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**copy_split(char **tab)
{
	char	**split;
	int		i;
	int		count;

	if (tab == NULL)
		return (NULL);
	count = count_split(tab);
	if ((split = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		split[i] = ft_strdup(tab[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
