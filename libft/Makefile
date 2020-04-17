# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 18:49:08 by iwillens          #+#    #+#              #
#    Updated: 2020/04/14 11:05:21 by iw               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SRCS = 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_itoa_base.c \
			ft_ftoa_base.c \
			ft_insertchr.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_islower_bonus.c \
			ft_isspace_bonus.c \
			ft_isupper_bonus.c \
			ft_putchar_bonus.c \
			ft_putnbr_bonus.c \
			ft_putstr_bonus.c \
			ft_isblank_bonus.c \
			ft_putendl_bonus.c \
			ft_strndup_bonus.c \
			ft_strtoupper.c \
			ft_itoa_base.c \
			ft_insertchr.c \
			ft_atoi.c \
			ft_ftoa_base.c \
			ft_negative_tozero.c \
			ft_bitcounter.c \
			ft_findstr.c \
			ft_vcalloc.c \
			ft_print_strarray.c \
			ft_free_strarray.c \
			ft_strarray_size.c \
			ft_replace.c \
			ft_isnumeric.c \
			ft_countchr.c

FLAGS = -Wno-nullability-completeness -Wall -Wextra -Werror
OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	ar -r $(NAME) $(OBJS)

OBJS : $(SRCS) $(HEADERS)
	@gcc $(FLAGS) -c  $(SRCS) -o $(OBJS)

clean: 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean libft.a
