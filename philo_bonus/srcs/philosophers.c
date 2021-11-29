/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:02:55 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 22:28:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo *philosophers_init(t_table *table)
{
    t_philo *philos;
    int i;

    philos = malloc(sizeof(t_philo) * table->number_of_philos);
    i = -1;
    while (++i < table->number_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].eat_count = 0;
        philos[i].table = table;
        philos[i].died = 0;
        pthread_mutex_init(&philos[i].died_mutex, NULL);
    }
    return (philos);
}

int    philosophers_doing(t_philo *philo)
{
    pthread_create(&philo->observer_id, NULL, observer, philo);
    if (philo->id % 2 == 0)
        usleep(1000);
    while (philo->died == 0)
    {
        if (taken_a_fork(philo) != 0)
            break ;
        if (eating(philo) != 0 || must_eat_checker(philo->table, philo->eat_count))
            break ;
        if (sleeping(philo) != 0)
            break ;
        if (thinking(philo) != 0)
            break ;
    }
    pthread_detach(philo->observer_id);
    return (0);
}