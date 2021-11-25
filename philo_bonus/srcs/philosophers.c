/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:02:55 by bahn              #+#    #+#             */
/*   Updated: 2021/11/25 21:30:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo *philosophers_init(t_table *table)
{
    t_philo *philos;
    int i;

    philos = malloc(sizeof(t_philo) * table->number_of_philos);
    i = -1;
    while (++i < table->number_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].eat_count = 0;
        philos[i].table = table;
        pthread_mutex_init(&philos[i].died_mutex, NULL);
        sem_wait(philos[i].table->terminate);
    }
    return (philos);
}
static  void    doing_on_pthread(t_philo *philo)
{
    philo->last_eat_time = time_ms();
    if (pthread_create(&philo->pthread_id, NULL, pthreadding, philo) != 0)
        ft_error(philo->table, "pthread create");
    if (pthread_create(&philo->observer_id, NULL, observer, philo) != 0)
        ft_error(philo->table, "pthread create");
}

static  void    join_of_pthread(t_philo *philo)
{
    if (pthread_join(philo->pthread_id, NULL) != 0)
        ft_error(philo->table, "pthread join");
    if (pthread_join(philo->observer_id, NULL) != 0)
        ft_error(philo->table, "pthread join");
    while (*(int *)philo->table->alive_philos > 0)
        usleep(100);
}
int    philosophers_doing(t_table *table)
{
    int child_pid;
    int i;

    i = -1;
    table->begin_time = time_ms();
    while (++i < table->number_of_philos)
    {
        child_pid = fork();
        if (child_pid == 0)
        {
            doing_on_pthread(&table->philos[i]);
            break ;
        }
    }
    if (child_pid == 0)
    {
        join_of_pthread(&table->philos[i]);
        return (CHILD_PROC);
    }
    else
        return (PARENT_PROC);
}