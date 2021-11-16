/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:44 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 16:41:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_philo *philo)
{
    printf("%ld %d is eating\n", timestamp_ms(philo->table->timestamp), philo->id);
    gettimeofday(&philo->timestamp->start, NULL);
    while (philo->table->died_philosopher == 0)
    {
        pthread_mutex_lock(&philo->table->die_check_mutex);
        if (philo->table->died_philosopher == 0 && timestamp_ms(philo->last_eat_time) >= philo->table->time_to_die)
        {
            printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
            pthread_mutex_unlock(&philo->table->die_check_mutex);
            return (++philo->table->died_philosopher);
        }
        pthread_mutex_unlock(&philo->table->die_check_mutex);
        if (timestamp_ms(philo->timestamp) >= philo->table->time_to_eat)
            break ;
    }
    if (philo->table->died_philosopher > 0)
        return (++philo->table->died_philosopher);
    gettimeofday(&philo->last_eat_time->start, NULL);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    return (0);
}