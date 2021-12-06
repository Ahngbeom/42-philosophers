/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:01:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 02:45:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	wait_for_philosophers(t_table *table)
{
	int	i;
	int	status;

	i = -1;
	while (++i < table->number_of_philos)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			i = -1;
			while (++i < table->number_of_philos)
				kill(table->philos_pid[i], SIGKILL);
			break ;
		}
	}
}

void	philosophers_on_process(t_table *table)
{
	int	i;

	gettimeofday(&table->begin_time, NULL);
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos_pid[i] = fork();
		if (table->philos_pid[i] < 0)
		{
			while (--i)
				kill(table->philos_pid[i], SIGKILL);
			exit_to_error(table, "fork error");
			break ;
		}
		else if (table->philos_pid[i] == 0)
		{
			philosophers_doing(&table->philos[i]);
		}
	}
	sem_wait(table->sem_end);
	wait_for_philosophers(table);
}
