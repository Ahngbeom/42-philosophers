/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:37:37 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 01:17:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	table_setting(t_table *table, int argc, char *argv[])
{
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
	table->philos_pid = malloc(sizeof(pid_t) * table->number_of_philos);
	table->someone_died = 0;
	table->ate_philos = 0;
	semaphore_init(table);
}

void	cleanup_table(t_table *table)
{
	int		i;

	semaphore_release(table);
	i = -1;
	while (++i < table->number_of_philos)
		pthread_mutex_destroy(&table->philos[i].mutex_protect);
	free(table->philos_pid);
	free(table->philos);
}
