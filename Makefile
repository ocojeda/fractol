# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 18:15:56 by ocojeda-          #+#    #+#              #
#    Updated: 2017/02/27 13:46:40 by ocojeda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra  
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRCS = main.c
LIBRARIES = libft/libft.a fractol.a
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(FLAGS) $(SRCS)
	@ar rc fractol.a $(OBJECTS)
	@ranlib fractol.a
	@gcc $(FLAGS) main.c $(LIBRARIES) -o $(NAME) $(MLXFLAGS)

clean:
	@rm -f $(OBJECTS) fractol.a main.o
	@make clean -C ./libft

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
