/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:20 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 16:30:14 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *pthreadding(void *data)
{
    t_philo *philo;

    philo = data;
    if (philo->id % 2 == 0)
        usleep(10);
    gettimeofday(&philo->last_eat_time->start, NULL);
    while (philo->table->died_philosopher == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
        if (eating(philo) != 0)
            break ;
        if (sleeping(philo) != 0)
            break ;
        if (thinking(philo) != 0)
            break ;
    }
    return (data);
}