/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csellier <csellier@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:52:13 by csellier          #+#    #+#             */
/*   Updated: 2016/01/16 21:01:24 by csellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 10

typedef struct		s_file
{
	char			*tmp;
	int				fd;
	struct s_file	*next;
}					t_file;

int					get_next_line(int const fd, char **line);
t_file				*ft_whitchfd(int fd, t_file **elem);
t_file				*ft_newt_file(int fd);
int					ft_check_tmp(t_file *f, char **line, char *buf,
		int whitch);
int					ft_check_buf(char *buf, char **line, t_file *f);

#endif
