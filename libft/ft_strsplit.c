/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:14:23 by csellier          #+#    #+#             */
/*   Updated: 2016/11/22 13:53:45 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	d;

	i = 0;
	j = 0;
	d = c;
	if (c == ' ')
		d = '\t';
	while (s[i])
	{
		while ((s[i] == c || s[i] == d) && s[i])
			i++;
		if (s[i] != c && s[i] != d && s[i])
			j++;
		while (s[i] != c && s[i] != d && s[i])
			i++;
	}
	return (j);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	size_t			j;
	int				k;
	char			**tab;
	char			d;

	i = 0;
	k = 0;
	d = (c == ' ') ? '\t' : c;
	tab = (char **)malloc(sizeof(char *) * (ft_countsplit(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s && (s[i] == c || s[i] == d) && s[i])
			i++;
		j = i;
		while (s && s[i] != c && s[i] != d && s[i])
			i++;
		if (j != i)
			tab[k++] = ft_strsub(s, j, (i - j));
	}
	tab[k] = NULL;
	return (tab);
}
