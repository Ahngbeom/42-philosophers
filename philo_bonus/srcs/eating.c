/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 23:41:54 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int eating(t_philo *philo)
{
    sem_wait(philo->sem_died);
    ft_print(philo->table, philo->id, "is eating");
    philo->last_eat_time = time_ms();
    philo->eat_count++;
    sem_post(philo->sem_died);
    while (time_ms() - philo->last_eat_time <= philo->table->time_to_eat)
        usleep(1000);
    sem_post(philo->table->sem_fork);
    sem_post(philo->table->sem_fork);
    return (philo->table->number_of_philos - *(int *)philo->table->alive_philos);
}

int must_eat_checker(t_table *table, int eat_count)
{
    if (table->must_eat == eat_count)
    {
        sem_wait(table->eat_finished_philos);
        return (1);
    }
    return (0);
}