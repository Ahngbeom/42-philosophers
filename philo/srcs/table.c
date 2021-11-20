/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:06 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 14:21:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    set_table(t_table *table, int argc, char *argv[])
{
    memset(table, 0, sizeof(t_table));
    table->number_of_philos = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    table->timestamp = 0;
    table->died_philos = 0;
    table->fork_mutex = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
    pthread_mutex_init(&table->status_mutex, NULL);
    if (argc == 5)
        table->must_eat = -1;
    if (argc == 6)
        table->must_eat = ft_atoi(argv[5]);
    philosophers_init(table);
}