/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:27 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:21:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int sleeping(t_philo *philo)
{
    int timestamp;

    pthread_mutex_lock(&philo->table->status_mutex);
    if (philo->table->died_philos == 0)
        printf("%d %d is sleeping\n", timestamp_ms() - philo->table->timestamp, philo->id);
    pthread_mutex_unlock(&philo->table->status_mutex);
    timestamp = timestamp_ms();
    while (timestamp_ms() - timestamp <= philo->table->time_to_sleep && \
            philo->table->died_philos == 0)
        usleep(1000);
    return (philo->table->died_philos);
}