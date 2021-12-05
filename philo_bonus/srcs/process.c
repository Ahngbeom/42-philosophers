/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/05 14:56:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	waiting_for_died_or_ate(t_table *table)
{
	while (table->someone_died == 0 && table->ate_all == 0)
	{
		usleep(1000);
	}
}

static	void	kill_philos_process(t_table *table, int number_of_philos)
{
	while (number_of_philos--)
	{
		if (kill(table->philos[number_of_philos].process_id, SIGTERM) == -1)
			exit_to_error(table, "kill error");
	}
}

void	philosophers_on_process(t_table *table)
{
	int	i;

	if (pthread_create(&table->died_pthread, NULL, pthread_someone_died, table))
		exit_to_error(table, "pthread create error");
	if (pthread_create(&table->atr_pthread, NULL, pthread_allofus_ate, table))
		exit_to_error(table, "pthread create error");
	if (pthread_detach(table->died_pthread))
		exit_to_error(table, "pthread detach error");
	if (pthread_detach(table->atr_pthread))
		exit_to_error(table, "pthread detach error");
	table->begin_time = ms_meter();
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].process_id = fork();
		if (table->philos[i].process_id < 0)
		{
			exit_to_error(table, "fork error");
			break ;
		}
		else if (table->philos[i].process_id == 0)
		{
			philosophers_doing(&table->philos[i]);
			exit(EXIT_SUCCESS);
		}
	}
	waiting_for_died_or_ate(table);
	kill_philos_process(table, i);
}
