/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:31:14 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 13:35:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_free(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->number_of_philos)
    {
        free(table->philos[i].last_eat_time);
	    free(table->philos[i].timestamp);
        table->philos[i].table = NULL;
        pthread_mutex_destroy(&table->fork_mutex[i]);
    }
    free(table->philos);
    pthread_mutex_destroy(&table->die_check_mutex);
    free(table->timestamp);
}