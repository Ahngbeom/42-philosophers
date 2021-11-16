/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:44:27 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 16:05:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int sleeping(t_philo *philo)
{
    printf("%ld %d is sleeping\n", timestamp_ms(philo->table->timestamp), philo->id);
    gettimeofday(&philo->timestamp->start, NULL);
    while (philo->table->died_philosopher == 0)
    {
        if (timestamp_ms(philo->timestamp) >= philo->table->time_to_sleep)
            break ;
        // usleep(10);
    }
    if (philo->table->died_philosopher > 0)
        return (philo->table->died_philosopher++);
    return (0);
}