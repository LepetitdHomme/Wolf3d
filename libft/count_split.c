/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:51:45 by csellier          #+#    #+#             */
/*   Updated: 2016/11/22 13:51:47 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_split(char **split)
{
	size_t	ret;

	ret = 0;
	if (split == NULL)
		return (0);
	while (split != NULL && split[ret])
		ret++;
	return (ret);
}
