# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 11:25:56 by jesssanc          #+#    #+#              #
#    Updated: 2025/01/27 10:57:45 by jesssanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS =  operations_swap.c			\
		operations_push.c			\
		operations_rotate.c			\
		operations_reverse_rotate.c	\
		push_swap.c					\
		numbers_utils.c				\
		algoritms.c					\
		algoritms_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS =
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR) AR="$(AR)"

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR) AR="$(AR)"

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(FT_PRINTF)

re: fclean all

.PHONY:		all clean fclean re bonus