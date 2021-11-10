/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:30 by bahn              #+#    #+#             */
/*   Updated: 2021/11/09 13:26:45 by bahn             ###   ########.fr       */
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
# include <string.h>
# include <stdlib.h>

typedef struct s_table t_table;
typedef struct s_list t_list;
typedef struct s_philo t_philo;
typedef	struct s_timestamp t_timestamp;

// t_timestamp timestamp;
pthread_mutex_t mutex;

struct s_table
{
	int	number_of_philos;
	int *fork;
	int	time_to_eat;
	int	time_to_sleep;

	long long *pthread_id;
	t_philo *philos;

	t_timestamp *timestamp;

	int died_check;
};

struct s_list
{
	void			*content;
	struct s_list	*next;
};

struct s_philo
{
	pthread_t pthread_id;
	int id;
	int	time_to_die;
	int	must_eat;

	t_table *table;
};

struct s_timestamp
{
	struct	timeval start;
	struct	timeval end;
};

// Table
t_table	*set_table(int argc, char **argv);
void	table_status(t_table *table);

// Queue
pthread_t	*queue_init(int size);
void	queue_status(pthread_t *queue, int size);
void	queue_rotate(pthread_t *queue, int size);

// Philosopher
t_philo	*philosopher_init(t_table *table, int time_to_die, int must_eat);
t_philo *create_philosopher(int id, int time_to_die, int must_eat);
int	death_check_philosophers(t_table *table);

// Timestamp
long int	timestamp_ms(t_timestamp *timestamp);

// Forks on the Table
int	count_fork(int *forks, int size);
int	taken_fork(t_table *table, int philo_id);
void	return_fork(t_table *table, int philo_id);

// Pthreading
void	eating(t_philo *philo, int limit);
void	sleeping(t_philo *philo, int limit);
void	thinking(t_philo *philo);

// void	*pthreading(void *data);
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
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif