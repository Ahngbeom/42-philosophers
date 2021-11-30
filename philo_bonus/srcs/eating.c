/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 14:06:38 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->died_mutex);
    ft_print(philo->table, philo->id, "is eating");
    philo->last_eat_time = time_ms();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->died_mutex);
    while (time_ms() - philo->last_eat_time <= philo->table->time_to_eat)
        usleep(1000);
    sem_post(philo->table->sem_fork);
    sem_post(philo->table->sem_fork);
    return (philo->died);
}

int must_eat_checker(t_table *table, int eat_count)
{
    if (table->must_eat == -1)
        return (0);
    else if (table->must_eat > eat_count)
        return (0);
    else 
    {
        // printf("must eat checker\n");
        sem_post(table->sem_ate);
        // sem_wait(table->sem_status);
        // while (table->all_of_us_ate == 0)
        //     usleep(10);
        return (1);
    }
}