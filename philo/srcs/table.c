/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/12/03 22:19:55 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*table_setting(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		table->must_eat = 0;
	else
	{
		table->must_eat = ft_atoi(argv[5]);
		if (table->must_eat == 0)
			exit(EXIT_SUCCESS);
	}
	invalid_arguments_checker(table);
	table->died_philos = 0;
	table->ate_philos = 0;
	table->fork_mutex = \
		malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	pthread_mutex_init(&table->preemptive_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	return (table);
}
