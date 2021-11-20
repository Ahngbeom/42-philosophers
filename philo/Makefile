# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 14:51:02 by bahn              #+#    #+#              #
#    Updated: 2021/11/21 04:04:14 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I./includes

RM = rm -fv

SRCS_PATH = ./srcs/
SRCS_FNAME = main.c table.c philosophers.c pthread.c \
			taken_a_fork.c \
			time_ms.c

UTILS_PATH = $(addprefix $(SRCS_PATH), utils/)
UTILS_FNAME = ft_atoi.c ft_print.c \
				ft_error.c ft_exception.c ft_free.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FNAME)) \
		$(addprefix $(UTILS_PATH), $(UTILS_FNAME))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) $(INCFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re