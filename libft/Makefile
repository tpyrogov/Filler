#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 21:56:04 by tpyrogov          #+#    #+#              #
#    Updated: 2017/10/31 23:00:55 by tpyrogov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRC= ./ft_atoi.c \
	./ft_bzero.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_islower.c \
	./ft_isprint.c \
	./ft_isspace.c \
	./ft_isupper.c \
	./ft_itoa.c \
	./ft_lstadd.c \
	./ft_lstdel.c \
	./ft_lstdelone.c \
	./ft_lstiter.c \
	./ft_lstmap.c \
	./ft_lstnew.c \
	./ft_memalloc.c \
	./ft_memccpy.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memdel.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_pow.c \
	./ft_putchar.c \
	./ft_putchar_fd.c \
	./ft_putendl.c \
	./ft_putendl_fd.c \
	./ft_putnbr.c \
	./ft_putnbr_fd.c \
	./ft_putstr.c \
	./ft_putstr_fd.c \
	./ft_strcat.c \
	./ft_strchr.c \
	./ft_strclr.c \
	./ft_strcmp.c \
	./ft_strcpy.c \
	./ft_strdel.c \
	./ft_strdup.c \
	./ft_strequ.c \
	./ft_striter.c \
	./ft_striteri.c \
	./ft_strjoin.c \
	./ft_strlcat.c \
	./ft_strlen.c \
	./ft_strmap.c \
	./ft_strmapi.c \
	./ft_strncmp.c \
	./ft_strncat.c \
	./ft_strncpy.c \
	./ft_strnequ.c \
	./ft_strnew.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strsplit.c \
	./ft_strstr.c \
	./ft_strsub.c \
	./ft_strtrim.c \
	./ft_tolower.c \
	./ft_toupper.c \
	./ft_swap.c \
	./ft_sort.c \
	./ft_gnome_sort.c \
	./ft_count_mass_el.c \
	./ft_del_mas.c \
	./ft_writetil.c \
	./ft_fill_new.c \
	./ft_count_digits.c \
	./get_next_line.c \
	./ft_printf/flags.c \
	./ft_printf/ft_printf.c \
	./ft_printf/init_flags.c \
	./ft_printf/helpers.c \
	./ft_printf/put_nbr_base.c \
	./ft_printf/types.c \
	./ft_printf/print_characters.c \
	./ft_printf/apply_format.c \
	./ft_printf/ft_stradd.c \
	./ft_printf/hendle_masks.c \
	./ft_printf/flags2.c \
	./ft_printf/apply_format_2.c
OBJ= $(SRC:.c=.o)
INC=./includes/%.h
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	@rm -f $(OBJ)
	@rm -f ./ft_printf/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
