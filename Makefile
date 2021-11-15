# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 18:20:36 by bahn              #+#    #+#              #
#    Updated: 2021/11/08 12:37:13 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCFLAGS = -I./includes

RM = rm -fv

SRCS_PATH = ./srcs/
SRCS_FNAME = main.c table.c pthread.c philosophers.c timestamp.c

# LIST_PATH = $(addprefix $(SRCS_PATH), list/)
# LIST_FNAME = ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c

UTILS_PATH = $(addprefix $(SRCS_PATH), utils/)
UTILS_FNAME = ft_atoi.c ft_bzero.c ft_calloc.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FNAME)) \
		$(addprefix $(UTILS_PATH), $(UTILS_FNAME)) \
		$(addprefix $(LIST_PATH), $(LIST_FNAME))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
		$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@
		$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o philo_one

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -lpthread -o $@
clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME) philo_one

re : fclean all

.PHONY : all clean fclean re


