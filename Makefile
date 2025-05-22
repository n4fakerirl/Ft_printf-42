# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 14:23:51 by ocviller          #+#    #+#              #
#    Updated: 2025/05/22 15:52:47 by ocviller         ###   ########.fr        #
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

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@ar rcs $(NAME) $(OBJ) $(LIBFT)
	@echo "$(NAME) created with libft !"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
