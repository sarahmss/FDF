# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2021/08/17 19:51:44 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= using_mlx
LIBFT	= libft.a
MLX		= libmlx.a

LIBFT_PATH		= ./libraries/libft/
MLX_PATH		= ./libraries/minilibx-linux/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.c				\
				using_mlx1.c		\
				using_mlx2_0.c		\
				using_mlx2_1.c		\
				using_mlx2_2.c		\
				using_mlx3.c		\
				using_mlx4.c		\
				using_mlx5.c


SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	using_mlx.h
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall  -Wextra
LIBRARIES	= -L$(LIBFT_PATH) -L$(MLX_PATH) -lmlx -lXext -lX11 -lft -lm
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)

all:		$(NAME)

#para que os objetos estão sendo usados?
$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(OBJS) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.c $(HEADERS)
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
$(MLX):
			@echo making minilibx...
			@echo --------------------------
			@make -sC $(MLX_PATH)
			@echo --------------------------
			@echo done!

$(LIBFT):
			@echo making libft...
			@echo --------------------------
			@make -sC $(LIBFT_PATH)
			@echo done!
			@echo --------------------------

clean:
			@make -sC $(LIBFT_PATH) fclean
			@make -sC $(LIBFT_PATH) clean
			@rm -f $(OBJS)
			@echo cleaned!
fclean:		clean
			@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
