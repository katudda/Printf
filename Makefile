# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 18:03:05 by kchristi          #+#    #+#              #
#    Updated: 2021/07/15 10:05:08 by kchristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

NAME = libftprintf.a

SRCS_PATH = srcs

SRCS =	$(SRCS_PATH)/ft_printf.c \
		$(SRCS_PATH)/ft_string_char.c \
		$(SRCS_PATH)/ft_pointer.c \
		$(SRCS_PATH)/ft_hex.c \
		$(SRCS_PATH)/ft_flags.c \
		$(SRCS_PATH)/ft_int.c \
		$(SRCS_PATH)/ft_percent.c \
		$(SRCS_PATH)/ft_printf_utils.c \
		$(SRCS_PATH)/ft_unsigned.c

OBJS_PATH = objs

OBJS = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRCS))

WHERE = .

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror



$(NAME):	$(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -I. -I/$(LIBFT_PATH) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	mv $(LIBFT) $(NAME)

all: $(NAME)

bonus: all

clean:
	@make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all fclean clean re