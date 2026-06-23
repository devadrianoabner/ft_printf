# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/23 14:08:38 by adrianda          #+#    #+#              #
#    Updated: 2026/06/23 15:45:06 by adrianda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	srcs/ft_printf.c\
		srcs/dispatch.c\
		srcs/conversions/handle_char.c\
		srcs/conversions/handle_str.c\
		srcs/conversions/handle_ptr.c\
		srcs/conversions/handle_int.c\
		srcs/conversions/handle_hex.c\
		srcs/conversions/handle_percent.c
		
OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
AR = ar rcs

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: all clean fclean re