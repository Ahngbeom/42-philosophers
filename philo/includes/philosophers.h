/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:27:24 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 16:56:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

struct s_table
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				begin_time;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;

	t_philo			*philos;
	int				died_philos;
};

struct s_philo
{
	pthread_t		pthread_id;
	pthread_t		observer_id;
	int				id;
	int				eat_count;
	int				last_eat_time;
	int				ate;
	int				timestamp;
	pthread_mutex_t	died_mutex;

	t_table			*table;
};

//	Utils
void	ft_exception(char *message);
void	ft_error(t_table *table, char *message);
void	ft_free(t_table *table);
int		ft_atoi(char *str);
void	invalid_arguments_checker(t_table *table);
int		must_eat_checker(t_table *table, t_philo *philo);
void	ft_print(t_table *table, int philo_id, char *action);
int		time_ms(void);

//	Table
t_table	*table_setting(int argc, char *argv[]);

//	Philosophers
t_philo	*philosophers_init(t_table *table);
void	philosophers_doing(t_table *table);
	//	Doing | Action
int		taken_a_fork(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);

//	Pthread
void	*pthreadding(void *data);
void	*observer(void *data);

#endif