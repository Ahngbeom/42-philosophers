/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:08 by bahn              #+#    #+#             */
/*   Updated: 2021/12/04 01:39:35 by bahn             ###   ########.fr       */
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
		table->must_eat = ft_atoi(argv[5]);
	invalid_arguments_checker(table);
	table->died_philos = 0;
	table->ate_philos = 0;
	table->fork_mutex = \
		malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	pthread_mutex_init(&table->print_mutex, NULL);
	return (table);
}

void	table_cleaning(t_table *table)
{
	int	i;

	if (table->philos != NULL)
	{
		i = -1;
		while (++i < table->number_of_philos)
		{
			pthread_mutex_destroy(&table->fork_mutex[i]);
			pthread_mutex_destroy(&table->philos[i].died_mutex);
			table->philos[i].table = NULL;
		}
		pthread_mutex_destroy(&table->print_mutex);
		free(table->philos);
	}
	free(table->fork_mutex);
	free(table);
}
