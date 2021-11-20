# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 18:20:36 by bahn              #+#    #+#              #
#    Updated: 2021/11/20 11:47:21 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I./includes

RM = rm -fv

SRCS_PATH = ./srcs/
SRCS_FNAME = main.c table.c philosopher.c pthread.c timestamp.c \
			taken_a_fork.c eating.c sleeping.c thinking.c

UTILS_PATH = $(addprefix $(SRCS_PATH), utils/)
UTILS_FNAME = ft_atoi.c ft_bzero.c ft_calloc.c ft_exception.c ft_error.c ft_free.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FNAME)) \
		$(addprefix $(UTILS_PATH), $(UTILS_FNAME)) \
		$(addprefix $(LIST_PATH), $(LIST_FNAME))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -lpthread -o $@
clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re


