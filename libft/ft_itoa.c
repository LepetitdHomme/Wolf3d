/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:57:34 by csellier          #+#    #+#             */
/*   Updated: 2015/12/17 19:53:42 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	int		cases;
	char	*chaine;

	neg = (n < 0) ? 1 : 0;
	cases = ft_intlen(n);
	chaine = (char *)malloc(sizeof(char) * (cases + neg + 1));
	if (chaine == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(chaine, "-2147483648"));
	chaine[cases + neg] = '\0';
	if (n < 0)
		n = -n;
	while (cases >= 0 + neg)
	{
		chaine[cases + neg - 1] = (n % 10) + 48;
		n = n / 10;
		cases--;
	}
	if (neg)
		chaine[0] = '-';
	return (chaine);
}
