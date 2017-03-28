# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csellier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 18:38:25 by csellier          #+#    #+#              #
#    Updated: 2016/11/22 15:14:25 by csellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
	  ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c ft_countchar.c ft_intlen.c ft_countword.c ft_lstnew.c\
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	  ft_isspace.c ft_strchri.c get_next_line.c ft_tablen.c count_split.c\
	  copy_split.c ft_copy_split.c ft_space.c ft_putendl_if.c ft_straddlast.c\


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
