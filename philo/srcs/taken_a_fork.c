/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:39:53 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 15:56:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int taken_a_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->fork_mutex[philo->id - 1]);
    if (philo->table->number_of_philos > 1)
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    else
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id]);
    printf("%ld %d taken a fork\n", timestamp_ms(philo->table->timestamp), philo->id);
    return (0);
}