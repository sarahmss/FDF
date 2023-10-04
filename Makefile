# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2023/10/04 14:45:00 by smodesto         ###   ########.fr        #
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

SRCS_FILES =	main.c		\
				draw.c		\
				img.c		\
				events.c	\
				menu.c		\
				init.c		\
				controls.c	\
				file_handling.c

SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	fdf.h	\
					structs.h
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Wextra  -g
LIBRARIES	= -L$(LIBFT_PATH) -L$(MLX_PATH) -lmlx -lXext -lX11 -lft -lm
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)

all:		$(NAME)

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
