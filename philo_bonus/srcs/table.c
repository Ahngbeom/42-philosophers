/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:19:37 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_table *table_setting(int argc, char *argv[])
{
    t_table *table;

    table = malloc(sizeof(t_table));
    table->number_of_philos = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (table->number_of_philos < 1 || table->time_to_die < 0 || table->time_to_eat < 0 || table->time_to_sleep < 0)
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
    // table->died_philos = 0;
    sem_fork = fork_init(table->number_of_philos);
    system("ls /dev/shm"); //Linux
    // system("ls /dev/sem");
    pthread_mutex_init(&table->print_mutex, NULL);
    table->philos = philosophers_init(table);
    return (table);
}