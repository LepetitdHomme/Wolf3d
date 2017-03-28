/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:53:44 by csellier          #+#    #+#             */
/*   Updated: 2016/09/28 16:40:53 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*ft_whitchfd(int fd, t_file **elem)
{
	t_file	*vagabond;

	if (*elem == NULL)
	{
		*elem = ft_newt_file(fd);
		return (*elem);
	}
	vagabond = *elem;
	while (vagabond->next != NULL && vagabond->fd != fd)
		vagabond = vagabond->next;
	if (vagabond->fd == fd)
		return (vagabond);
	vagabond->next = ft_newt_file(fd);
	return (vagabond->next);
}

t_file	*ft_newt_file(int fd)
{
	t_file *new;

	new = (t_file *)malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->tmp = NULL;
	new->next = NULL;
	return (new);
}

int		ft_check_tmp(t_file *f, char **line, char *buf, int whitch)
{
	char	*tmp2;

	if ((whitch == 1) && ft_strchri(f->tmp, '\n') >= 0)
	{
		*line = ft_strsub(f->tmp, 0, ft_strchri(f->tmp, '\n'));
		if ((f->tmp)[ft_strchri(f->tmp, '\n') + 1])
			tmp2 = ft_strdup(f->tmp + (ft_strchri(f->tmp, '\n')) + 1);
		else
			tmp2 = NULL;
		free(f->tmp);
		f->tmp = tmp2;
		return (1);
	}
	else if (whitch == 0)
	{
		if (f->tmp != NULL)
		{
			tmp2 = ft_strjoin(f->tmp, buf);
			free(f->tmp);
			f->tmp = tmp2;
		}
		else
			f->tmp = ft_strdup(buf);
	}
	return (-1);
}

int		ft_check_buf(char *buf, char **line, t_file *f)
{
	int		i;
	char	*ch;

	ch = NULL;
	if ((i = ft_strchri(buf, '\n')) >= 0)
	{
		if (f->tmp != NULL)
		{
			ch = ft_strsub(buf, 0, i);
			*line = ft_strjoin(f->tmp, ch);
			free(f->tmp);
			free(ch);
		}
		else
			*line = ft_strsub(buf, 0, (size_t)i);
		if (buf[i + 1])
			f->tmp = ft_strdup(buf + i + 1);
		else
			f->tmp = NULL;
		return (1);
	}
	return (-1);
}

int		get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_file	*elem = NULL;
	t_file			*elemtmp;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL)
		return (-1);
	elemtmp = ft_whitchfd(fd, &elem);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (elemtmp->tmp != NULL && ft_check_tmp(elemtmp, line, buf, 1) != -1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_check_buf(buf, line, elemtmp) == 1)
			return (1);
		ft_check_tmp(elemtmp, line, buf, 0);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == 0 && elemtmp->tmp != NULL)
	{
		*line = elemtmp->tmp;
		elemtmp->tmp = NULL;
		return (1);
	}
	return (ret);
}
