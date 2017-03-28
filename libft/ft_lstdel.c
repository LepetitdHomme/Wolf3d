/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:38:53 by csellier          #+#    #+#             */
/*   Updated: 2015/12/21 17:34:04 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *ptrnxt;

	ptr = *alst;
	while (ptr)
	{
		ptrnxt = (ptr)->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = ptrnxt;
	}
	*alst = NULL;
}
