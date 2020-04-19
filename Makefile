# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:49:08 by iwillens          #+#    #+#              #
#    Updated: 2020/04/17 09:25:15 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORK_MAC = -framework OpenGL -framework AppKit

FRAMEWORK_LINUX = -lXext -lX11 -lbsd -lm

MLX_DIR = ./minilibx-linux-master

MLX = -L$(MLX_DIR) -lmlx

LIBFT_DIR = ./libft

LIBFT = -L./$(LIBFT_DIR) -lft

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)

FLAGS = -Wall -Werror -Wextra -Wno-nullability-completeness -g

NAME = cub3D

HEADERS = cub3d.h

SRCS = 	c3d_gfx_texture.c \
		c3d_gfx_utils.c \
		c3d_gfx_texture_draw.c \
		c3d_gfx_bmp.c \
		c3d_init.c \
		c3d_keys.c \
		c3d_mem_alloc.c \
		c3d_mem_free.c \
		c3d_mov_move.c \
		c3d_raycasting.c \
		c3d_read_file.c \
		c3d_read_gnl.c \
		c3d_read_map.c \
		c3d_read_map_util.c \
		c3d_read_textures.c \
		c3d_trigonometry.c \
		c3d_error_handling.c \
		c3d_sprites.c \
		cub3d.c 
		   
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	clang $(FLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(FRAMEWORK_LINUX) -o $(NAME)

%.o : %.c $(HEADERS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	clang -c $(FLAGS) $< $(INCLUDES) -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean: 
	@rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
