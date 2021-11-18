/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:44 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 23:42:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->die_check_mutex);
    printf("%d %d is eating\n", timestamp_ms() - philo->table->timestamp, philo->id);
    philo->last_eat_time = timestamp_ms();
    pthread_mutex_unlock(&philo->die_check_mutex);
    while (timestamp_ms() - philo->last_eat_time <= philo->table->time_to_eat && \
            philo->table->died_philosopher == 0)
    {
        usleep(1000);
    }
    if (philo->table->died_philosopher > 0)
        return (1);
    philo->must_eat--;
    philo->last_eat_time = timestamp_ms();
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    return (0);
}