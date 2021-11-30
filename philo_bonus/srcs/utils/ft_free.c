/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:29:52 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 14:23:11 by bahn             ###   ########.fr       */
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
    sem_unlink("fork");

    sem_close(table->sem_print);
    sem_unlink("print");

    sem_close(table->sem_status);
    sem_unlink("status");

    if (table->someone_died != 0)
        sem_close(table->sem_died);
    sem_unlink("died");

    if (table->all_of_us_ate != 0)
        sem_close(table->sem_ate);
    sem_unlink("ate");
}