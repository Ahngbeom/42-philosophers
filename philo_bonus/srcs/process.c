/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/02 13:44:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	waiting_for_died_or_ate(t_table *table)
{
	while (table->someone_died == 0 && table->all_of_us_ate == 0)
	{
		usleep(10);
	}
}

static	void	kill_philos_process(t_philo *philos, int number_of_philos)
{
	while (number_of_philos--)
		kill(philos[number_of_philos].process_id, SIGTERM);
}

void	philosophers_on_process(t_table *table)
{
	int	i;

	if (pthread_create(&table->mutex_died, NULL, pthread_someone_died, table))
		exit_to_error(table, "pthread create error");
	if (pthread_create(&table->mutex_ate, NULL, pthread_allofus_ate, table))
		exit_to_error(table, "pthread create error");
	if (pthread_detach(table->mutex_died))
		exit_to_error(table, "pthread detach error");
	if (pthread_detach(table->mutex_ate))
		exit_to_error(table, "pthread detach error");
	table->begin_time = ms_meter();
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].process_id = fork();
		if (table->philos[i].process_id > 0)
			continue ;
		else if (table->philos[i].process_id < 0)
			exit_to_error(table, "fork error");
		else
			philosophers_doing(&table->philos[i]);
	}
	waiting_for_died_or_ate(table);
	kill_philos_process(table->philos, table->number_of_philos);
}
