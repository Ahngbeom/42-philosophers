/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:41:03 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:19:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    *observer(void *data)
{
    t_philo *philo;

    philo = data;
    while (died_philos == 0)
    {
        pthread_mutex_lock(&philo->died_mutex);
        if (time_ms() - philo->last_eat_time >= table->time_to_die)
        {
            ft_print(table, philo->id, "died");
            ++died_philos;
            pthread_mutex_unlock(&philo->died_mutex);
            printf("[focus philoID %d] died philos : %d\n", philo->id, died_philos);
            break ;
        }
        pthread_mutex_unlock(&philo->died_mutex);
        usleep(10);
    }
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
    while (died_philos == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
        if (eating(philo) != 0 || must_eat_checker(table))
            break ;
        if (sleeping(philo) != 0)
            break ;
        if (thinking(philo) != 0)
            break ;
    }
    return (data);
}