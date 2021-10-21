# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 18:20:36 by bahn              #+#    #+#              #
#    Updated: 2021/10/21 18:34:08 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -gcc
INCFLAGS = -I./includes

RM = rm -fv

SRCS_PATH = ./srcs/
SRCS_NAME = philosophers.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re


