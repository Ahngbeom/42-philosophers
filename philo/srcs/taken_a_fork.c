/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:39:53 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:34:58 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int taken_a_fork(t_philo *philo)
{
    if (philo->table->number_of_philos == 1)
    {
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id - 1]);
        printf("%d %d has taken a fork\n", timestamp_ms() - philo->table->timestamp, philo->id);
        while (philo->table->died_philos == 0)
            usleep(1000);
        pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
    }
    else
    {
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id - 1]);
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
        pthread_mutex_lock(&philo->table->status_mutex);
        if (philo->table->died_philos == 0)
            printf("%d %d has taken a fork\n", timestamp_ms() - philo->table->timestamp, philo->id);
        pthread_mutex_unlock(&philo->table->status_mutex);
    }
    return (philo->table->died_philos);
}