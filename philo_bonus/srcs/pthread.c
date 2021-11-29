/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:41:03 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 22:06:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    *someone_died_on_pthread(void *data)
{
    t_table *table;

    table = data;
    sem_wait(table->sem_died);
    table->someone_died++;
    return (table);
}

void    *allofus_ate_on_pthread(void *data)
{
    t_table *table;
    int i;
    
    table = data;
    i = -1;
    while (++i < table->number_of_philos)
        sem_wait(table->sem_ate);
    table->all_of_us_ate++;
    return (table);
}

void    *observer(void *data)
{
    t_philo *philo;

    philo = data;
    while (philo->died == 0)
    {
        pthread_mutex_lock(&philo->died_mutex);
        if (philo->table->someone_died == 0 && time_ms() - philo->last_eat_time >= philo->table->time_to_die)
        {
            sem_wait(philo->table->sem_status);
            ft_print(philo->table, philo->id, "died");
            philo->died++;
            sem_post(philo->table->sem_died);
            pthread_mutex_unlock(&philo->died_mutex);
            break ;
        }
        pthread_mutex_unlock(&philo->died_mutex);
		usleep(10);
    }
    return (philo);
}

