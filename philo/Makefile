# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 14:51:02 by bahn              #+#    #+#              #
#    Updated: 2021/12/07 15:01:15 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname -s)

NAME 		= philo

CC 			= gcc

ifeq ($(OS), Linux)
LEAK_FLAGS 	= -g3 -fsanitize=address -static-libasan
else
LEAK_FLAGS 	= -g3 -fsanitize=address -static-libsan
endif

CFLAGS 		= -Wall -Werror -Wextra #$(LEAK_FLAGS)

INCFLAGS 	= -I./includes

RM 			= rm -fv

SRCS_PATH 	= ./srcs/
SRCS_FNAME 	= main.c table.c philosophers.c pthread.c \
				taken_a_fork.c eating.c sleeping.c thinking.c \
				timems_meter.c

UTILS_PATH 	= $(addprefix $(SRCS_PATH), utils/)
UTILS_FNAME = ft_atoi.c ft_error.c ft_exception.c ft_printf.c 

SRCS 		= $(addprefix $(SRCS_PATH), $(SRCS_FNAME)) \
				$(addprefix $(UTILS_PATH), $(UTILS_FNAME))
OBJS 		= $(SRCS:.c=.o)

all 		: $(NAME)

.c.o 		: $(SRCS)
			$(CC) $(CFLAGS) $(INCFLAGS) -c $^ -o $@

ifeq ($(OS), Linux)
$(NAME) 	: $(OBJS)
			$(CC) $(CFLAGS) $(INCFLAGS) $^ -lpthread -o $@
else
$(NAME) 	: $(OBJS)
			$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@
endif
clean 		: 
			$(RM) $(OBJS)

fclean 		: clean
			$(RM) $(NAME)

re 			: fclean all

.PHONY 		: all clean fclean re