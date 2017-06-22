# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 18:15:56 by ocojeda-          #+#    #+#              #
#    Updated: 2017/06/22 13:24:07 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAMEBIN = fractol.a
FLAGS = -Wall -Wextra -Werror
INC = includes
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRC_PATH = srcs
OBJ_PATH = obj
LIBFT_PATH = libft
LIBFTA = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFTA))
SRC_NAME = algo_burning_ship.c algo_mandelbrot.c burning_ship.c color.c julia.c \
		   mandel.c algo_julia.c aux_julia.c clean.c hook_funcs.c main.c map.c
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) ./$(NAMEBIN)
	@ar rc $(NAMEBIN) $(OBJS)
	@ranlib $(NAMEBIN)
	@gcc -o $(NAME) $(NAMEBIN) $(MLXFLAGS)
	@echo "$(GREEN)--------Fdf compiled--------$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -rf $(NAMEBIN)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---Fdf removed completely---$(NC)"

re: fclean all
