/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 15:26:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static  void    *pthread_someone_died(void *data)
{
    t_table *table;

    table = data;
    sem_wait(table->sem_died);
    table->someone_died++;
    return (table);
}

static  void    *pthread_allofus_ate(void *data)
{
    t_table *table;
    int i;

    table = data;
    i = -1;
    while (++i < table->number_of_philos)
    {
        sem_wait(table->sem_ate);
        if (table->someone_died != 0)
            return (table);
    }
    table->someone_died++;
    table->all_of_us_ate++;
    return (table);
}

void    create_philos_process(t_table *table)
{
    int i;

    pthread_create(&table->mutex_died, NULL, pthread_someone_died, table);
    pthread_create(&table->mutex_ate, NULL, pthread_allofus_ate, table);
    table->begin_time = millisecond_meter();
    i = -1;
    while (++i < table->number_of_philos)
    {
        table->philos[i].process_id = fork();
        if (table->philos[i].process_id == 0)
        {
            philosophers_doing(&table->philos[i]);
        }
        else if (table->philos[i].process_id < 0)
            exit(EXIT_FAILURE);
    }
    while (table->someone_died == 0 && table->all_of_us_ate == 0)
        usleep(100);
    i = -1;
    while (++i < table->number_of_philos)
    {
        kill(table->philos[i].process_id, SIGTERM);
    }
}