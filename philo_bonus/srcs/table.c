/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/11/25 20:50:01 by bahn             ###   ########.fr       */
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
    if (argc == 5)
        table->must_eat = -1;
    else
        table->must_eat = ft_atoi(argv[5]);
    if (table->number_of_philos < 1 || table->time_to_die <= 0 || table->time_to_eat <= 0 || \
            table->time_to_sleep <= 0 || (argc == 6 && table->must_eat == -1))
    {
        ft_exception("Invalid argument for Philosophers program");
        free(table);
    }
    semaphore_init_on_table(table, table->must_eat);
    table->philos = philosophers_init(table);
    return (table);
}