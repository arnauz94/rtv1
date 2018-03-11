# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avinas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 19:56:03 by avinas            #+#    #+#              #
#    Updated: 2018/03/11 14:57:52 by avinas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean $(NAME) fclean re all

NAME	= rtv1

SRC		= 	srcs/main.c			\
			srcs/get_next_line.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -rf obj/
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

test: re
	./fdf

all: $(NAME)
