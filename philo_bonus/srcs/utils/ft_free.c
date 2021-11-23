/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:29:52 by bahn              #+#    #+#             */
/*   Updated: 2021/11/22 21:14:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_free(t_table *table)
{
    // int i;

    if (table->philos != NULL)
    {
        // i = -1;
        // while (++i < table->number_of_philos)
        // {
        //     pthread_mutex_destroy(&table->fork_mutex[i]);
        //     pthread_mutex_destroy(&table->philos[i].died_mutex);
        // }
        // pthread_mutex_destroy(&table->print_mutex);
        // table->philos[i].table = NULL;
        free(table->philos);
    }
}