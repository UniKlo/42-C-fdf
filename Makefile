#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 18:08:35 by khou              #+#    #+#              #
#    Updated: 2018/11/15 20:18:30 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = fdf

FLAGS = -Wall -Wextra -Werror # -fsanitize=address #-g

DIR_H = incl/

DIR_S = srcs/

HEADER = fdf.h

SOURCES = main.c\

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

INCL = $(addprefix $(DIR_H), $(HEADER))

FW = -framework OpenGL -framework AppKit

LIB_1 = -L libft/ -lft

LIB_2 = -L minilibx_macos/ -lmlx $(FW)

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/
	@make -C minilibx_macos/
	@$(C) -I $(INCL) $(FLAGS) $(LIB_1) $(LIB_2) $(SRCS) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@make clean -C libft
	@make clean -C minilibx_macos/
	@echo "fdf cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f include/*~
	@rm -f include/\#*\#
	@rm -f srcs/*~
	@rm -f srcs/\#*\#
	@rm -f srcs/.#*
	@rm -f a.out
	@rm -rf *dSYM
	@make fclean -C libft
	@echo "fdf reset"

re: fclean all

.PHONY: fclean re norme all clean
