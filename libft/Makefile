# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/07 12:14:16 by jemagnie     #+#   ##    ##    #+#        #
#    Updated: 2019/01/30 18:41:32 by jemagnie    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_strlen.c ft_isupper.c \
	  ft_islower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strcmp.c ft_strncmp.c \
	  ft_strstr.c ft_strnstr.c ft_memalloc.c ft_putchar.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c \
	  ft_putendl.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_number_len.c ft_itoa.c \
	  ft_strchr.c ft_strrchr.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_nbword.c ft_wordlen.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_memcmp.c ft_memccpy.c ft_memmove.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_lstlen.c ft_isspace.c ft_isblank.c \
	  ft_itoa_base.c ft_sqrt.c ft_power.c ft_strjoinint.c ft_strjoinchar.c \
	  ft_error.c ft_ishexa.c ft_max.c ft_min.c ft_swap.c get_next_line.c \
	  ft_strndup.c ft_putbits.c ft_puthex.c ft_mask.c ft_isbin.c ft_isocta.c \
	  ft_atoi_more.c get_next_len.c ft_lstadd_end.c ft_del.c ft_atoi_ptr.c \
	  ft_strwhile.c ft_lstprint.c ft_atoi_more_ptr.c ft_doubletab_del.c \
	  ft_memdelzero.c ft_wstrlen.c ft_putwstr.c ft_wclen.c ft_putwchar.c \
	  get_next_free.c ft_strupper.c ft_free_zero.c ft_printf.c number.c \
	  parse.c print.c string.c tools.c ft_int_abs.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "library created : $(NAME)"
	@ar rc $(NAME) $(OBJ)

norme:
	norminette $(SRC)

%.o: %.c libft.h
	@gcc $(FLAG) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
