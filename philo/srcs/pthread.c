/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:20 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 15:52:12 by bahn             ###   ########.fr       */
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
        taken_a_fork(philo);
        if (eating(philo) != 0)
        {
            break ;
        }
        if (sleeping(philo) != 0)
        {
            break ;
        }
        thinking(philo);
    }
    return (data);
}