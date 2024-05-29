# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 16:47:30 by ctacconi          #+#    #+#              #
#    Updated: 2024/05/28 20:11:51 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = srcs/main.c srcs/check_args.c srcs/utils.c srcs/init.c srcs/render.c srcs/events.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = Makefile fractol.h

RM = rm -f

# Implicit method
%.o: %.c Makefile inc/fractol.h ft_printf/libftprintf.a
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

# My methods
all: make_libs $(NAME)

make_libs:
	Make -C mlx/
	Make -C ft_printf/

$(NAME): $(OBJ) 
	cp ft_printf/libftprintf.a $(NAME)
	$(CC) $(NAME) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	$(RM) $(OBJ)
	Make -C mlx/ clean
	Make -C ft_printf/ clean

fclean: clean
	$(RM) $(NAME)
	Make -C ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re