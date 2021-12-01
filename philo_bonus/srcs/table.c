/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:37:37 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 15:16:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    table_setting(t_table *table, int argc, char *argv[])
{
    table->number_of_philos = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 5)
        table->must_eat = 0;
    else
    {
        table->must_eat = ft_atoi(argv[5]);
        if (table->must_eat == 0)
            exit(EXIT_SUCCESS);
    }
    invalid_arguments_checker(table);
    table->someone_died = 0;
    table->all_of_us_ate = 0;
    semaphore_init(table);
}

void    cleanup_table(t_table *table)
{
    int i;
    char    *sem_name;
    char    *id;

    if (table->all_of_us_ate == 0)
        sem_post(table->sem_ate);
    else
        sem_post(table->sem_died);
    sem_close(table->sem_fork);
    sem_unlink("/fork");
    sem_close(table->sem_print);
    sem_unlink("/print");
    sem_close(table->sem_preemptive);
    sem_unlink("/preemptive");
    sem_close(table->sem_died);
    sem_unlink("/died");
    sem_close(table->sem_ate);
    sem_unlink("/ate");
    i = -1;
    while (++i < table->number_of_philos)
    {
        sem_close(table->philos[i].sem_protect);
        id = ft_itoa(table->philos[i].id);
        sem_name = ft_strjoin("/protect_", id);
        sem_unlink(sem_name);
        free(id);
        free(sem_name);
    }
    // free(table->philos);
}