/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:37:37 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 15:00:29 by bahn             ###   ########.fr       */
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
        table->must_eat = -1;
    else
        table->must_eat = ft_atoi(argv[5]);

    if ((table->number_of_philos <= 0 || table->number_of_philos >= 200) || \
        table->time_to_die < 60 || table->time_to_eat < 60 || table->time_to_sleep < 60 || \
        (argc == 6 && table->must_eat <= 0))
        exit(EXIT_FAILURE);

    table->someone_died = 0;
    table->all_of_us_ate = 0;

    sem_unlink("/fork");
    table->sem_fork = sem_open("/fork", O_CREAT | O_EXCL, 0644, table->number_of_philos);

    sem_unlink("/print");
    table->sem_print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);

    sem_unlink("/status");
    table->sem_status = sem_open("/status", O_CREAT | O_EXCL, 0644, 1);

    sem_unlink("/died");
    table->sem_died = sem_open("/died", O_CREAT | O_EXCL, 0644, 0);

    sem_unlink("/ate");
    table->sem_ate = sem_open("/ate", O_CREAT | O_EXCL, 0644, 0);
}