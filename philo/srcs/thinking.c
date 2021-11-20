/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:21:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->status_mutex);
    if (philo->table->died_philos == 0)
        printf("%d %d is thinking\n", timestamp_ms() - philo->table->timestamp, philo->id);
    pthread_mutex_unlock(&philo->table->status_mutex);
    return (philo->table->died_philos);
}