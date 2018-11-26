# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varuiz <varuiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:20:04 by varuiz            #+#    #+#              #
#    Updated: 2018/11/26 06:39:10 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean all

NAME = fillit
LIB = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
RM = rm -f
HEADER = ./
SRC = 	main.c				\
		ft_create_map.c 	\
		ft_map_min.c 		\
		ft_piece_letter.c 	\
		ft_put_piece.c 		\
		ft_solve.c 			\
		ft_tabmalloc.c 		\
		ft_piece_fit.c 		\
		ft_save_piece.c 	\
		ft_reset_piece.c 	\
		ft_valid.c			\
		ft_freetab.c		\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
			make -C ./libft
			$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I$(HEADER)

%.o: %.c
	$(CC) -I$(HEADER) -o $@ -c $? $(FLAGS) 

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft

fclean: clean
			$(RM) $(NAME)
			make fclean -C ./libft

re: fclean all
