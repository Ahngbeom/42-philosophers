/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:30 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:21:03 by bahn             ###   ########.fr       */
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
typedef struct s_philo t_philo;
typedef	struct s_timestamp t_timestamp;

struct s_table
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int must_eat;
	pthread_mutex_t *fork_mutex;
	pthread_mutex_t status_mutex;

	t_philo *philos;
	int died_philos;

	int	timestamp;
};

struct s_philo
{
	pthread_t pthread_id;
	pthread_t observer_id;
	int id;
	int	must_eat;
	int	last_eat_time;
	pthread_mutex_t died_mutex;
	t_table *table;
};

struct s_timestamp
{
	struct	timeval start;
	struct	timeval end;
};


void	set_table(t_table *table, int argc, char *argv[]);

void	philosophers_init(t_table *table);
void    philosophers_doing(t_table *table);
void    philosophers_stop(t_table *table);

void    *pthreadding(void *data);
void    *observer(void *data);

int taken_a_fork(t_philo *philo);
int eating(t_philo *philo);
int sleeping(t_philo *philo);
int thinking(t_philo *philo);

int timestamp_ms(void);

// Utils
int	ft_atoi(char *str);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void    ft_exception(void);
void	ft_error(char *err_msg);
void    ft_free(t_table *table);

#endif