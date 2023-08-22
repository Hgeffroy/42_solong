# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2023/06/11 08:35:38 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = so_long
FLAGS = -Wall -Wextra -Werror -Iheader #-fsanitize=address -g3
MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-fsanitize=address -g3
CC = cc
RM = rm -f
OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libprintf/
LIBFT = libftprintf.a
MLX_DIR = mlx_linux
HEADER = header/so_long.h

#Files

SRC_F = get_next_line.c \
		get_next_line_utils.c \
		display_map.c \
		parsing.c \
		parsing_utils.c \
		free.c \
		commands.c \
		movements.c \
		utils.c \
		init.c \
		init_utils.c \
		so_long.c
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

#Rules

all : lib mlx $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT_DIR)$(LIBFT) $(HEADER) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT_DIR)$(LIBFT) -o $@

lib :
	make -C $(LIBFT_DIR)

mlx :
	make -C $(MLX_DIR)

clean :
	$(RM) -r $(OBJ_DIR) libft.a
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all