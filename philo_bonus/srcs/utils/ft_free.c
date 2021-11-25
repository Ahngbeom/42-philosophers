/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:29:52 by bahn              #+#    #+#             */
/*   Updated: 2021/11/25 19:44:57 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_free(t_table *table)
{
    int i;

    if (table->philos != NULL)
    {
        i = -1;
        while (++i < table->number_of_philos)
        {
            pthread_mutex_destroy(&table->philos[i].died_mutex);
            table->philos[i].table = NULL;
        }
        free(table->philos);
    }
    sem_close(table->sem_fork);
    sem_close(table->sem_print);
    sem_close(table->terminate);
    sem_close(table->alive_philos);
    sem_unlink("fork");
    sem_unlink("print");
    sem_unlink("terminate");
    sem_unlink("alive_philos");
    if (table->must_eat != -1)
    {
        sem_close(table->eat_finished_philos);
        sem_unlink("eat_finished_philos");
    }
}