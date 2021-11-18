/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:27 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 13:00:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int sleeping(t_philo *philo)
{
    int timestamp;

    printf("%d %d is sleeping\n", timestamp_ms() - philo->table->timestamp, philo->id);
    timestamp = timestamp_ms();
    while (timestamp_ms() - timestamp <= philo->table->time_to_sleep && \
            philo->table->died_philosopher == 0)
    {
        usleep(1000);
    }
    if (philo->table->died_philosopher > 0)
        return (1);
    return (0);
}