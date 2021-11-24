/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:41:03 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 23:28:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    *observer(void *data)
{
    t_philo *philo;

    philo = data;
    
    while (*(int *)philo->table->alive_philos == philo->table->number_of_philos)
    {
        sem_wait(philo->sem_died);
        if (philo->table->must_eat == philo->eat_count)
        {
            sem_post(philo->sem_died);
            return (data);
        }
        if (time_ms() - philo->last_eat_time >= philo->table->time_to_die)
        {
            ft_print(philo->table, philo->id, "died");
            sem_wait(philo->table->alive_philos);
            philo->died++;
            sem_post(philo->sem_died);
            return (data);
        }
        sem_post(philo->sem_died);
        usleep(10);
    }
    sem_wait(philo->table->alive_philos);
    return (data);
}

void    *pthreadding(void *data)
{
    t_philo *philo;

    philo = data;
    if (philo->id % 2 == 0)
    {
        usleep(1000);
    }
    while (philo->died == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
        if (eating(philo) != 0 || must_eat_checker(philo->table, philo->eat_count))
            break ;
        if (sleeping(philo) != 0)
            break ;
        if (thinking(philo) != 0)
            break ;
    }
    return (data);
}