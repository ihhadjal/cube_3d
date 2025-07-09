# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:33:52 by ilhasnao          #+#    #+#              #
#    Updated: 2025/07/09 03:34:18 by ilhasnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT = resources/libft/
RM = rm -f
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC_1 = code/main.c code/parsing/parsing.c code/utils/utils.c code/parsing/skiplines_logic.c \
		code/utils/utils2.c code/parsing/flood_fill.c code/utils/utils3.c code/utils/utils4.c \
		code/raycasting/init.c code/raycasting/movement.c code/raycasting/utils.c code/raycasting/dda.c \
		code/raycasting/draw.c code/raycasting/angles_n_color.c code/raycasting/free.c \

OBJ_1 = $(SRC_1:.c=.o)

INCLUDE = -L resources/libft -lft

DEF_COLOR = \033[0m
PINK = \033[5;95m
GREEN = \033[1;92m
CYAN = \033[1;96m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PINK)I'm compiling hbibi!$(DEF_COLOR)"
	
$(NAME): $(OBJ_1)
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE} $(MLX_FLAGS)
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

$(NAME_BONUS):  $(OBJ_2)
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_2} -o ${NAME_BONUS} ${INCLUDE} $(MLX_FLAGS)
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

mlx:
		git clone https://github.com/42Paris/minilibx-linux.git mlx || true
		make -C mlx

all: ${NAME}

clean:
		@${RM} ${OBJ_1} $(OBJ_2)
		@cd ${LIBFT} && $(MAKE) clean
		@echo "$(CYAN)I'm cleaning hbibi!$(DEF_COLOR)"

fclean: clean
		@${RM} ${NAME} ${NAME_BONUS}
		@cd ${LIBFT} && $(MAKE) fclean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

re: clean all

.PHONY: all clean fclean re bonus mlx re_bonus
