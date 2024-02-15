# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:43:44 by sagemura          #+#    #+#              #
#    Updated: 2024/02/15 18:23:28 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helper_func.a
LIBFTNAME = libft.a
PHILOCOMPNAME = philo_components.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_close.c ft_time.c print_behavior.c routine.c threads.c
LIBFTDIR = ./libft
PHILOCOMPDIR = ./philo_components

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(PHILOCOMPDIR)
	ar rcs $(NAME) $(OBJ) $(LIBFTDIR)/$(LIBFTNAME) $(PHILOCOMPDIR)/$(PHILOCOMPNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(PHILOCOMPDIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) fclean -C $(PHILOCOMPDIR)
	rm -f $(NAME)

re: fclean all 
