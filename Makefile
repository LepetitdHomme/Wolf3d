NAME = wolf3d

CC = gcc

FLAGS = -Wall -Werror -Wextra

OS = Linux

SRC =   animation.c\
		bmp.c\
		bmp2.c\
		bmp3.c\
		colors.c\
		error.c\
		expose.c\
		floor_casting.c\
		get_length.c\
		Init_level.c\
		Init_textures.c\
		main.c\
		move.c\
		raycasting.c\
		refresh.c\
		rotate.c\
		set_image.c\
		static.c\
		texture.c\
		tools.c\


INC = structures.h wolf.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INC) $(OBJ)
	make -C libft/
    ifeq ($(shell uname -s),Linux)
		$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -L X11/ -lmlx -lft -lXext -lX11 -lm -pthread
    else
		$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L libft/ -lft -lmlx -lm -framework OpenGL -framework AppKit
    endif

%.o : %.c structures.h wolf.h
	$(CC) $(FLAGS) -I. -c $<

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re :  fclean all
