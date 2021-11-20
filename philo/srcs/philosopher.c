/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:14:07 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:32:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philosophers_init(t_table *table)
{
    int i;

    table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
    if (table->philos == NULL)
        ft_error("malloc - philo");
    i = -1;
    while (++i < table->number_of_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].must_eat = table->must_eat;
        table->philos[i].table = table;
        table->philos[i].last_eat_time = 0;
        pthread_mutex_init(&table->philos[i].died_mutex, NULL);
        pthread_mutex_init(&table->fork_mutex[i], NULL);
    }
}

void    philosophers_doing(t_table *table)
{
    int i;

    table->timestamp = timestamp_ms();
    i = -1;
    while (++i < table->number_of_philos)
    {
        table->philos[i].last_eat_time = timestamp_ms();
        if (pthread_create(&table->philos[i].pthread_id, NULL, pthreadding, &table->philos[i]))
        {
            ft_error("pthread create error");
        }
        if (pthread_create(&table->philos[i].observer_id, NULL, observer, &table->philos[i]))
        {
            ft_error("pthread create error");
        }
    }
    i = -1;
    while (++i < table->number_of_philos)
    {
        if (pthread_join(table->philos[i].pthread_id, NULL) != 0)
        {
            ft_error("pthread join error");
        }
        if (pthread_join(table->philos[i].observer_id, NULL) != 0)
        {
            ft_error("pthread join error");
        }
    }
}

void    philosophers_stop(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->number_of_philos)
    {
        pthread_mutex_destroy(&table->fork_mutex[i]);
    }
}