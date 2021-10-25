/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:30 by bahn              #+#    #+#             */
/*   Updated: 2021/10/25 17:59:23 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define _XOPEN_SOURCE 500

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_list t_list;
typedef struct s_philo t_philo;

struct s_list
{
	pthread_t pth_id;
	void			*content;
	struct s_list	*next;
};

struct s_philo
{
	int id;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	
	int must_eat;
};

t_list *philosopher_init(int argc, char **argv, int number_of_philos);
t_philo *create_philosopher(int argc, char **argv, int id);
void	philosopher_status(t_list *philos);

int	ft_atoi(char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

#endif