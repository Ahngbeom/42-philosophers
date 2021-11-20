/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:41:03 by bahn              #+#    #+#             */
/*   Updated: 2021/11/21 04:56:11 by bahn             ###   ########.fr       */
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
        if (time_ms() - philo->last_eat_time >= philo->table->time_to_die)
        {
            ft_print(philo->table, philo->id, "died");
            philo->table->died_philos++;
        }
        pthread_mutex_unlock(&philo->died_mutex);
    }
    return (data);
}

void    *pthreadding(void *data)
{
    t_philo *philo;

    philo = data;
    while (philo->table->died_philos == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
    }
    return (data);
}