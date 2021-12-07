/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:02:55 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:57:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers_init(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (table->philos == NULL)
		ft_error(table, "malloc error");
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].ate_it_all = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->fork_mutex[i], NULL) != 0)
			ft_error(table, "pthread mutex init");
		if (pthread_mutex_init(&table->philos[i].died_mutex, NULL) != 0)
			ft_error(table, "pthread mutex init");
	}
}

void	philosophers_doing(t_table *table)
{
	int	i;

	gettimeofday(&table->begin_time, NULL);
	i = -1;
	while (++i < table->number_of_philos)
	{
		gettimeofday(&table->philos[i].last_eat_time, NULL);
		if (pthread_create(&table->philos[i].pthread_id, NULL, \
								pthreadding, &table->philos[i]))
			ft_error(table, "pthread create error");
		if (pthread_create(&table->philos[i].observer_id, NULL, \
								observer, &table->philos[i]))
			ft_error(table, "pthread create error");
	}
	i = -1;
	while (++i < table->number_of_philos)
	{
		if (pthread_join(table->philos[i].pthread_id, NULL))
			ft_error(table, "pthread join error");
		if (pthread_join(table->philos[i].observer_id, NULL))
			ft_error(table, "pthread join error");
	}
}
