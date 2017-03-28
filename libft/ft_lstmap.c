/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:36:41 by csellier          #+#    #+#             */
/*   Updated: 2016/02/15 15:19:00 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *ret;

	if (!f || !lst)
		return (NULL);
	tmp = f(lst);
	if ((ret = ft_lstnew(tmp->content, tmp->content_size)))
	{
		new = ret;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
	}
	return (ret);
}
