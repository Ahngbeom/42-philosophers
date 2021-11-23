/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:20:23 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->died_mutex);
    ft_print(table, philo->id, "is eating");
    philo->last_eat_time = time_ms();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->died_mutex);
    while (time_ms() - philo->last_eat_time <= table->time_to_eat)
        usleep(1000);
    sem_post(sem_fork[philo->id - 1]);
    sem_post(sem_fork[philo->id % table->number_of_philos]);
    printf("[focus philoID %d] died philos : %d\n", philo->id, died_philos);
    return (died_philos);
}

int must_eat_checker(t_table *table)
{
    int i;

    if (table->must_eat == -1)
        return (0);
    i = -1;
    while (++i < table->number_of_philos)
    {
        if (table->philos[i].eat_count < table->must_eat)
            return (0);
    }
    return (1);
}