/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:27:24 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 22:04:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

# define PARENT_PROC 1
# define CHILD_PROC 0

typedef struct s_table t_table;
typedef struct s_philo t_philo;

struct s_table
{
    int number_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
    int begin_time;

    pthread_t   mutex_died;
    pthread_t   mutex_ate;

    sem_t *sem_fork;
    sem_t *sem_print;
    sem_t *sem_status;
    sem_t *sem_died;
    sem_t *sem_ate;

    int someone_died;
    int all_of_us_ate;
    
    t_philo *philos;
};

struct s_philo
{
    pid_t   process_id;
    pthread_t pthread_id;
    pthread_t observer_id;
    int id;
    int eat_count;
    int last_eat_time;
    int timestamp;
    int died;
    pthread_mutex_t died_mutex;

    t_table *table;
};

void    ft_exception(char *message);
void    ft_error(t_table *table, char *message);
void    ft_free(t_table *table);

int	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int	ft_atoi(char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

t_table *table_setting(int argc, char *argv[]);

t_philo *philosophers_init(t_table *table);

// Semaphore
void    semaphore_init_on_table(t_table *table);

// Process
void	process_on_philosophers(t_table *table);

// Pthread
void    *someone_died_on_pthread(void *data);
void    *allofus_ate_on_pthread(void *data);
void    *observer(void *data);

// Doing of Philosophers
int philosophers_doing(t_philo *philo);
int taken_a_fork(t_philo *philo);
int eating(t_philo *philo);
int sleeping(t_philo *philo);
int thinking(t_philo *philo);

int must_eat_checker(t_table *table, int eat_count);

void    ft_print(t_table *table, int philo_id, char *action);

int time_ms(void);

#endif