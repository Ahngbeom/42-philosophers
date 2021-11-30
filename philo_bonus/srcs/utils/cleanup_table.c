/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:24:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 19:06:14 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    cleanup_table(t_table *table)
{
    int i;
    char    *sem_name;

    if (table->all_of_us_ate == 0)
        sem_post(table->sem_ate);
    else
        sem_post(table->sem_died);
    
    sem_close(table->sem_fork);
    sem_close(table->sem_print);
    sem_close(table->sem_status);
    sem_close(table->sem_died);
    sem_close(table->sem_ate);
    sem_unlink("/fork");
    sem_unlink("/print");
    sem_unlink("/status");
    sem_unlink("/died");
    sem_unlink("/ate");
    i = -1;
    while (++i < table->number_of_philos)
    {
        sem_close(table->philos[i].sem_protect);
        sem_name = ft_strjoin("/protect_", ft_itoa(table->philos[i].id));
        sem_unlink(sem_name);
        free(sem_name);
    }
    free(table->philos);
}