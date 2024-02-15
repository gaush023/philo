# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:43:44 by sagemura          #+#    #+#              #
#    Updated: 2024/02/15 19:01:32 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HELPERFUNC = helper_func.a
LIBFTNAME = libft.a
PHILOCOMPNAME = philo_components.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c
HELPERFUNCDIR = ./helper_func
LIBFTDIR = ./helper_func/libft
PHILOCOMPDIR = ./helper_func/philo_components

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)	
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(PHILOCOMPDIR)
	$(MAKE) -C $(HELPERFUNCDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(HELPERFUNCDIR)/$(HELPERFUNC) $(LIBFTDIR)/$(LIBFTNAME) $(PHILOCOMPDIR)/$(PHILOCOMPNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	$(MAKE) clean -C $(HELPERFUNCDIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(HELPERFUNCDIR)
	rm -f $(NAME)

re: fclean all 
