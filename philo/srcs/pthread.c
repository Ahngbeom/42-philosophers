/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:20 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 23:41:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *observer(void *data)
{
    t_philo *philo;

    philo = data;
    while (1)
    {
        pthread_mutex_lock(&philo->die_check_mutex);
        if (philo->table->died_philosopher > 0)
        {
            philo->table->died_philosopher++;
            break ;
        }
        else if (timestamp_ms() - philo->last_eat_time >= philo->table->time_to_die)
        {
            philo->table->died_philosopher++;
            printf("%d %d is died\n", timestamp_ms() - philo->table->timestamp, philo->id);
            break ;
        }
        pthread_mutex_unlock(&philo->die_check_mutex);
    }
    pthread_join(philo->pthread_id, NULL);
    return (data);
}

void    *pthreadding(void *data)
{
    t_philo *philo;

    philo = data;
    if (philo->id % 2 == 0)
        usleep(10);
    philo->last_eat_time = timestamp_ms();
    while (philo->table->died_philosopher == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
        if (eating(philo) != 0)
            break ;
        if (sleeping(philo) != 0)
            break ;
        if (thinking(philo) != 0)
            break ;
    }
    return (data);
}