/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 19:20:37 by csellier          #+#    #+#             */
/*   Updated: 2016/02/22 17:44:10 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*s3;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	s3 = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1) + ft_strlen(s2)));
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		s3[i] = s2[k];
		i++;
		k++;
	}
	s3[i] = '\0';
	return (s3);
}
