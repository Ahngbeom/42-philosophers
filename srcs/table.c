/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:49:56 by bahn              #+#    #+#             */
/*   Updated: 2021/11/08 14:05:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*set_table(int argc, char **argv)
{
	t_table *table;
	int i;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		exit(EXIT_FAILURE);
	table->number_of_philos = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		table->philos = philosopher_init(table, ft_atoi(argv[2]), -1);
	else if (argc == 6)
		table->philos = philosopher_init(table, ft_atoi(argv[2]), ft_atoi(argv[5]));
	table->pthread_id = ft_calloc(sizeof(pthread_t), table->number_of_philos + 1);
	if (table->number_of_philos > 1)
		table->fork_mutex = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	else
		table->fork_mutex = malloc(sizeof(pthread_mutex_t) * 2);
	pthread_mutex_init(&table->die_check_mutex, NULL);
	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_mutex_init(&table->fork_mutex[i++], NULL);
		if (table->number_of_philos == 1)
			pthread_mutex_init(&table->fork_mutex[i], NULL);
	}
	table->timestamp = malloc(sizeof(t_timestamp));
	table->died_philosopher = 0;
	return (table);
}
