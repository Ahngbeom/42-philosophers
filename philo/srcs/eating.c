/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/22 00:49:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->died_mutex);
    ft_print(philo->table, philo->id, "is eating");
    philo->last_eat_time = time_ms();
    pthread_mutex_unlock(&philo->died_mutex);
    while (time_ms() - philo->last_eat_time <= philo->table->time_to_eat)
        usleep(1000);
    // philo->last_eat_time = time_ms();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
    pthread_mutex_unlock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    return (philo->table->died_philos);
}

int must_eat_checker(t_table *table)
{
    int i;

    if (table->must_eat == -1)
        return (0);
    i = -1;
    while (++i < table->number_of_philos)
    {
        if (table->philos[i].eat_count < table->must_eat)
            return (0);
    }
    return (1);
}