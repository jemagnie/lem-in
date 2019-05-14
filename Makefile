# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/21 15:38:44 by jemagnie     #+#   ##    ##    #+#        #
#    Updated: 2019/03/26 15:31:51 by jemagnie    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = lem-in
FLAG = -Wall -Wextra -Werror
SRC = srcs/lemin.c srcs/parse.c srcs/get.c srcs/avl.c \
	  srcs/rotate.c srcs/mem.c srcs/tool.c srcs/solve.c
OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAG) libft/libft.a $(OBJ) -o $(NAME) 
	@echo "lem-in created"

%.o: %.c ./include/lemin.h
	@gcc $(FLAG) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY : all clean fclean re