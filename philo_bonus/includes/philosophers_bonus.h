/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:27:24 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 13:34:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h> // EXIT_SUCCESS | EXIT_FAILURE
# include <fcntl.h> // O_CREAT | O_EXCEL
# include <string.h> // memset()
# include <unistd.h> // usleep()
# include <signal.h> // kill()
# include <sys/time.h> // struct timeval
# include <sys/wait.h> // waitpid(), WNOHANG, WIFEXITED(status)

# define PARENT_PROC 1
# define CHILD_PROC 0

typedef struct timeval	t_timeval;

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	pid_t		*philos_pid;

	int			number_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;

	int			someone_died;
	int			ate_philos;

	t_timeval	begin_time;

	sem_t		*sem_fork;
	sem_t		*sem_print;
	sem_t		*sem_end;

	pthread_t	pthread_id;

	t_philo		*philos;
};

struct s_philo
{
	pthread_t		observer_id;
	int				id;

	int				died;
	int				ate;

	t_timeval		last_eat_time;
	int				eat_count;

	pthread_mutex_t	mutex_protect;

	t_table			*table;
};

//  Libft
int		ft_atoi(char *str);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);

//  Utils
int		timems_meter(t_timeval *time);
void	protected_printf(t_table *table, int philo_id, char *action);
void	exception(char *message);
void	invalid_arguments_checker(t_table *table);
void	exit_to_error(t_table *table, char *message);

//  Table
void	table_setting(t_table *table, int argc, char *argv[]);
void	cleanup_table(t_table *table);

//  Semaphore
void	semaphore_init(t_table *table);
void	semaphore_release(t_table *table);

//  Pthread
void	*pthread_someone_died(void *data);
void	*pthread_allofus_ate(void *data);
void	*pthread_observer(void *data);

//  Philosophers
void	philosophers_init(t_table *table);
	//  Process
void	philosophers_on_process(t_table *table);
	//  Doing | Action 
void	philosophers_doing(t_philo *philo);
int		taken_a_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

#endif