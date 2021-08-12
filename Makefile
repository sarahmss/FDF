# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2021/08/11 21:48:50 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
LIBFT	= libft.a
MLX		= libmlx.a

LIBFT_PATH		= ./libraries/libft/
MLX_PATH		= ./libraries/minilibx-linux/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.c			\
				using_mxl.c
SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	fdf.h
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
LIBRARIES	= -L$(LIBFT_PATH) -L$(MLX_PATH) -lmlx -lXext -lX11 -lft
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
			echo cleaned!
fclean:		clean
			@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
