# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 14:51:02 by bahn              #+#    #+#              #
#    Updated: 2021/11/24 23:45:01 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS	= $(shell uname -s)

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I./includes

RM = rm -rfv

SRCS_PATH = ./srcs/
SRCS_FNAME = main.c table.c time_ms.c \
			philosophers.c pthread.c \
			taken_a_fork.c eating.c sleeping.c thinking.c \
			#semaphore.c
LIBFT_PATH = $(addprefix $(SRCS_PATH), libft/)
LIBFT_FNAME = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_itoa.c ft_strjoin.c

UTILS_PATH = $(addprefix $(SRCS_PATH), utils/)
UTILS_FNAME = ft_error.c ft_exception.c ft_free.c ft_print.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FNAME)) \
		$(addprefix $(LIBFT_PATH), $(LIBFT_FNAME)) \
		$(addprefix $(UTILS_PATH), $(UTILS_FNAME))

OBJS = $(SRCS:.c=.o)
# OBJS_PATH = ./objs
# OBJS = $(addprefix $(OBJS_PATH)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

# $(OBJS_PATH):
# 	mkdir -p $@
	
.c.o : $(SRCS)
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# $(OBJS): $(OBJS_PATH)/%.o: %.c | $(OBJS_PATH)
# 	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

ifeq ($(OS), Linux)
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -lpthread -lrt -o $@
else
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(INCFLAGS) $^ -o $@
endif

clean : 
	$(RM) $(OBJS) 

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re