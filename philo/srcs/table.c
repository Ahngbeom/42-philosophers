/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/21 03:32:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table *table_setting(char *argv[])
{
    t_table *table;

    table = malloc(sizeof(t_table));
    table->number_of_philos = ft_atoi(argv[1]);
    if (table->number_of_philos < 1)
    {
        ft_exception("Invalid argument for Philosophers program");
        free(table);
    }
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    table->begin_time = 0;
    table->died_philos = 0;
    table->fork_mutex = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
    pthread_mutex_init(&table->print_mutex, NULL);
    return (table);
}