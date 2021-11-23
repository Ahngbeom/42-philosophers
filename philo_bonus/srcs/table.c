/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/22 21:12:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_table *table_setting(int argc, char *argv[])
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
    if (table->time_to_die < 0)
    {
        ft_exception("Invalid argument for Philosophers program");
        free(table);
    }
    table->time_to_eat = ft_atoi(argv[3]);
    if (table->time_to_eat < 0)
    {
        ft_exception("Invalid argument for Philosophers program");
        free(table);
    }
    table->time_to_sleep = ft_atoi(argv[4]);
    if (table->time_to_sleep < 0)
    {
        ft_exception("Invalid argument for Philosophers program");
        free(table);
    }
    if (argc == 5)
        table->must_eat = -1;
    else
    {
        table->must_eat = ft_atoi(argv[5]);
        if (table->must_eat < 0)
            ft_exception("Invalid argument for Philosophers program");
    }
    table->died_philos = 0;
    table->fork_semaphore = sem_open("fork_semaphore", O_CREAT, 0777, 1);
    // pthread_mutex_init(&table->print_mutex, NULL);
    return (table);
}