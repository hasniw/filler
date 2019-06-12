# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 09:48:30 by wahasni           #+#    #+#              #
#    Updated: 2019/06/12 04:06:16 by wahasni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wahasni.filler

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = ./srcs/

INCDIR = ./include/

LIB = ./libft

SRCS = $(SRCDIR)check.c\
	   $(SRCDIR)ft_count_word.c\
	   $(SRCDIR)ft_free.c\
	   $(SRCDIR)ft_handle_map.c\
	   $(SRCDIR)ft_handle_piece.c\
	   $(SRCDIR)ft_init_player.c\
	   $(SRCDIR)ft_isndigit.c\
	   $(SRCDIR)ft_resolve.c\
	   $(SRCDIR)main.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@$(CC) -I $(INCDIR) $(FLAGS) -o $@ $(OBJS) $(LIB)/libft.a
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c $(INCDIR)/filler.h
	@$(CC) -o $@ -c $< -I $(INCDIR) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS)
	@make -C $(LIB) clean
	@echo "rm *.o\033[0;32m ✓\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIB) fclean
	@echo "rm $(NAME)\033[0;32m ✓\033[0m"

re: fclean all

.PHONY: all clean fclean re