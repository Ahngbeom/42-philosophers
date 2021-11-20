/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:44 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:38:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->died_mutex);
    pthread_mutex_lock(&philo->table->status_mutex);
    if (philo->table->died_philos == 0)
        printf("%d %d is eating\n", timestamp_ms() - philo->table->timestamp, philo->id);
    pthread_mutex_unlock(&philo->table->status_mutex);
    philo->last_eat_time = timestamp_ms();
    pthread_mutex_unlock(&philo->died_mutex);
    while (timestamp_ms() - philo->last_eat_time <= philo->table->time_to_eat && \
            philo->table->died_philos == 0)
        usleep(1000);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    if (philo->must_eat > 0)
        philo->must_eat--;
    return (philo->table->died_philos);
}