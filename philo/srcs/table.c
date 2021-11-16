/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:59:06 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 14:38:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    set_table(t_table *table, int argc, char *argv[])
{
    table->number_of_philos = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    table->timestamp = malloc(sizeof(t_timestamp));
    table->died_philosopher = 0;
    if (argc == 5)
        philosophers_init(table, -1);
    if (argc == 6)
        philosophers_init(table, ft_atoi(argv[5]));

    pthread_mutex_init(&table->die_check_mutex, NULL);
}