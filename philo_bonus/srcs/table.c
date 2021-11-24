/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 23:41:44 by bahn             ###   ########.fr       */
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
    sem_unlink("alive_philos");
    sem_unlink("fork");
    sem_unlink("print");
    sem_unlink("terminate");
    sem_unlink("eat_finished_philos");
    table->alive_philos = sem_open("alive_philos", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    table->sem_fork = sem_open("fork", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    table->sem_print = sem_open("print", O_CREAT | O_EXCL, 0777, 1);
    table->terminate = sem_open("terminate", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    if (argc == 5)
    {
        table->must_eat = -1;
        table->eat_finished_philos = NULL;
    }
    else
    {
        table->must_eat = ft_atoi(argv[5]);
        table->eat_finished_philos = sem_open("eat_finished_philos", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    }
    system("ls /dev/shm"); //Linux
    // system("ls /dev/sem");
    table->philos = philosophers_init(table);
    return (table);
}