# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:04:04 by ctacconi          #+#    #+#              #
#    Updated: 2024/05/05 10:16:03 by carolinat        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c

OBJ = $(SRC:.c=.o)

# BONUS=ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c	\
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

# BONUS_OBJ=$(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = Makefile fractol.h mlx/mlx.h

#LIB=ar rcs

RM=rm -f

all: $(NAME)

make_libs:
	Make -C mlx/

$(NAME): $(OBJ) make_libs
	$(LIB) $(NAME) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Imlx -o $@ -c $<

clean:
	$(RM) $(OBJ) #$(BONUS_OBJ)
	Make -C mlx/ clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

#bonus: $(OBJ) $(BONUS_OBJ) Makefile libft.h
	$(LIB) $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re #bonus
