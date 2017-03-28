/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:34 by csellier          #+#    #+#             */
/*   Updated: 2016/12/09 17:31:35 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_last(char *str, char c)
{
	int		i;
	int		count;
	char	*ret;

	count = (str == NULL) ? 0 : ft_strlen(str);
	if ((ret = (char *)malloc(sizeof(char) * (count + 2))) == NULL)
		return (NULL);
	i = 0;
	while (str && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	return (ret);
}
