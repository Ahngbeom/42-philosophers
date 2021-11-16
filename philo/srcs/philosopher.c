/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:14:07 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 15:11:10 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    philosophers_init(t_table *table, int must_eat)
{
    int i;

    table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
    if (table->number_of_philos > 1)
        table->fork_mutex = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
    else
        table->fork_mutex = malloc(sizeof(pthread_mutex_t) * 2);
    if (table->philos == NULL)
        ft_error("malloc - philo");
    i = -1;
    while (++i < table->number_of_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].must_eat = must_eat;
        table->philos[i].table = table;
        table->philos[i].timestamp = malloc(sizeof(t_timestamp));
        table->philos[i].last_eat_time = malloc(sizeof(t_timestamp));
        pthread_mutex_init(&table->fork_mutex[i], NULL);
    }
}

void    philosophers_running(t_table *table)
{
    int i;

    gettimeofday(&table->timestamp->start, NULL);
    i = -1;
    while (++i < table->number_of_philos)
    {
        pthread_create(&table->philos[i].pthread_id, NULL, pthreadding, &table->philos[i]);
    }
    while (1)
    {
        if (table->died_philosopher > 0)
            break ;
    }
}

void    philosophers_stop(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->number_of_philos)
    {
        pthread_join(table->philos[i].pthread_id, NULL);
    }
}