/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:34:32 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 14:24:26 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	process_on_philosophers(t_table *table)
{
	int i;

    pthread_create(&table->mutex_died, NULL, someone_died_on_pthread, table);
    if (table->must_eat != -1)
        pthread_create(&table->mutex_ate, NULL, allofus_ate_on_pthread, table);
    i = -1;
    table->begin_time = time_ms();
    while (++i < table->number_of_philos)
    {
        table->philos[i].process_id = fork();
        if (table->philos[i].process_id == 0)
        {
			table->philos[i].last_eat_time = time_ms();
            philosophers_doing(&table->philos[i]);
            break ;
        }
    }
    while (table->someone_died == 0 && table->all_of_us_ate == 0)
		usleep(1000);
    pthread_detach(table->mutex_died);
	if (table->must_eat != -1)
        pthread_detach(table->mutex_ate);
	i = -1;
	while (++i < table->number_of_philos)
    {
		kill(table->philos[i].process_id, SIGTERM);
    }
}