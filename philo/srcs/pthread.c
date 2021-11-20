/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:20 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:34:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *observer(void *data)
{
    t_philo *philo;

    philo = data;
    while (philo->table->died_philos == 0)
    {
        pthread_mutex_lock(&philo->died_mutex);
        if (timestamp_ms() - philo->last_eat_time >= philo->table->time_to_die)
        {
            pthread_mutex_lock(&philo->table->status_mutex);
            if (philo->table->died_philos == 0)
                printf("%d %d is died\n", timestamp_ms() - philo->table->timestamp, philo->id);
            philo->table->died_philos++;
            pthread_mutex_unlock(&philo->table->status_mutex);
            pthread_mutex_unlock(&philo->died_mutex);
            break ;
        }
        pthread_mutex_unlock(&philo->died_mutex);
    }
    return (data);
}

void    *pthreadding(void *data)
{
    t_philo *philo;

    philo = data;
    if (philo->id % 2 == 0)
        usleep(1000);
    while (philo->table->died_philos == 0)
    {
        if (taken_a_fork(philo) > 0)
            break ;
        if (eating(philo) > 0 || philo->must_eat == 0)
            break ;
        if (sleeping(philo) > 0)
            break ;
        if (thinking(philo) > 0)
            break ;
    }
    philo->table->died_philos++;
    return (data);
}