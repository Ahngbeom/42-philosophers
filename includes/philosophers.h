/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:30 by bahn              #+#    #+#             */
/*   Updated: 2021/11/01 13:44:25 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define _XOPEN_SOURCE 500

# define TRUE 1
# define FALSE 0

# define SUCCESS 1
# define FAILURE 0

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <malloc.h>

typedef struct s_table t_table;
typedef struct s_list t_list;
typedef struct s_philo t_philo;

struct s_table
{
	int number_of_philosophers;
	int *fork;
	int time_to_eat;
	int time_to_sleep;
	t_philo **philos;

	// timestamp
	struct timeval ts_start;
	struct timeval ts_end;

	// mutex
	pthread_mutex_t	mutex_lock;

	pthread_t *queue;
};

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct s_philo
{
	t_table *table;
	pthread_t pth_id;
	struct timeval ts_start;
	struct timeval ts_end;
	int id;
	int time_to_die;
	int must_eat;
};

// Table
t_table	*set_table(int argc, char **argv);
void	table_status(t_table *table);

// Queue
pthread_t	*queue_init(int size);
void	queue_status(pthread_t *queue, int size);
void	queue_rotate(pthread_t *queue, int size);

// Philosopher
void	philosopher_init(t_table *table, int time_to_die, int must_eat);
t_philo *create_philosopher(int id, int time_to_die, int must_eat);
void	death_check_philosophers(t_table *table);

// Timestamp
int	timestamp_ms(t_table *table);

// Forks on the Table
int	count_fork(int *forks, int size);
int	taken_fork(t_table *table, int philo_id);
void	return_fork(t_table *table, int philo_id);

// Pthreading
void	pthreading(t_table *table);
void	*pthread_eating(void *data);
void	*pthread_sleeping(void *data);
void	*pthread_thinking(void *data);

// List
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

// Utils
int	ft_atoi(char *str);
void	*ft_memset(void *s, int n, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif