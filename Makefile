# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 14:23:51 by ocviller          #+#    #+#              #
#    Updated: 2025/05/19 15:04:47 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printchar.c ft_printnb.c ft_printstr.c ft_printhex.c \
	ft_printuns.c ft_printmem.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) tmp_libft.a
	@ar x tmp_libft.a
	@ar rcs $(NAME) $(OBJ) *.o
	@rm -f tmp_libft.a *.o
	@echo "$(NAME) created with libft symbols!"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed."

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
