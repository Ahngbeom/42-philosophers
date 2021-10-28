/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:30 by bahn              #+#    #+#             */
/*   Updated: 2021/10/28 23:24:15 by bahn             ###   ########.fr       */
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

};

struct s_list
{
	pthread_t pth_id;
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
	// int time_to_eat;
	// int time_to_sleep;
	int must_eat;
	
};

// Table
t_table	*set_table(int argc, char **argv);
void	table_status(t_table *table);

// Philosopher
void	philosopher_init(t_table *table, int time_to_die, int must_eat);
t_philo *create_philosopher(int id, int time_to_die, int must_eat);
void	death_check_philosophers(t_table *table);

// Timestamp
int	timestamp_ms(t_table *table);

// Utils
int	ft_atoi(char *str);
void	*ft_memset(void *s, int n, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// Forks on the Table
int	count_fork(int *forks, int size);
int	taken_fork(t_table *table, int philo_id);
void	return_fork(t_table *table, int philo_id);

// Pthreading
void	pthreading(t_table *table);
void	*pthread_eating(void *data);
void	*pthread_sleeping(void *data);
void	*pthread_thinking(void *data);

#endif