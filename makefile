# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 15:15:26 by hbruvry           #+#    #+#              #
#    Updated: 2018/01/08 12:43:08 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_backtrack.c ft_checkerror.c ft_filecpy.c main.c

OBJ =		$(patsubst %.c, %.o, $(SRCS))

NAME =		fillit

LIBFT =		Libft/

CFLAGS =	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT)
	gcc $(CFLAGS) -c $(addprefix , $(SRCS))
	gcc $(CFLAGS) $(OBJ) Libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY : libft clean fclean all re
