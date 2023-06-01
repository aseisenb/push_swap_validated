# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:35:27 by aseisenb          #+#    #+#              #
#    Updated: 2022/10/21 15:35:28 by aseisenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a

LIBFT_PATH = ./libraries/libft/
INCLUDES = ./includes

SRC = ./source/

FILES = $(SRC)choose_rotation.c $(SRC)push_swap.c $(SRC)operations.c $(SRC)sort_helpers.c $(SRC)quick_sort.c $(SRC)error_and_clear.c $(SRC)init.c $(SRC)stack_helpers.c $(SRC)parse_argc.c $(SRC)send_to_b.c $(SRC)return_to_a.c $(SRC)reduce_operations.c $(SRC)small_sort.c $(SRC)return_to_a_sorting.c
OBJECTS = choose_rotation.o push_swap.o operations.o sort_helpers.o quick_sort.o error_and_clear.o  init.o stack_helpers.o parse_argc.o send_to_b.o return_to_a.o reduce_operations.o small_sort.o return_to_a_sorting.o

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

clean:
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 
