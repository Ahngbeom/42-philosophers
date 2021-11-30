/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 16:04:04 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    eating(t_philo *philo)
{
    sem_wait(philo->table->sem_fork);
    protected_printf(philo->table, philo->id, "taken a fork");
    sem_wait(philo->table->sem_fork);
    protected_printf(philo->table, philo->id, "taken a fork");
    sem_wait(philo->sem_protect);
    protected_printf(philo->table, philo->id, "is eating");
    philo->last_eat_time = millisecond_meter();
    sem_post(philo->sem_protect);
    while ((millisecond_meter() - philo->last_eat_time <= philo->table->time_to_eat) && \
            philo->table->someone_died == 0)
    {
        usleep(1000);
    }
    philo->eat_count++;
    sem_post(philo->table->sem_fork);
    sem_post(philo->table->sem_fork);
}