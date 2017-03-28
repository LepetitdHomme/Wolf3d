/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:53:32 by csellier          #+#    #+#             */
/*   Updated: 2017/01/27 17:53:35 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		error(int i)
{
	if (i == 0)
		ft_putendl_fd("error: fopen failed", 2);
	else if (i == 1)
		ft_putendl_fd("error: file header not detected", 2);
	else if (i == 2)
		ft_putendl_fd("error: image header incoherence", 2);
	else if (i == 3)
		ft_putendl_fd("error: bmp data issue", 2);
	else if (i == 4)
		ft_putendl_fd("error: bmp palette issue", 2);
	exit(EXIT_FAILURE);
	return (0);
}
