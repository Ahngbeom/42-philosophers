/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:43:39 by bahn              #+#    #+#             */
/*   Updated: 2021/11/08 14:04:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	count_fork(int *forks, int size)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (size == 1)
		size++;
	while (i < size)
	{
		if (forks[i++] == 0)
			count++;
	}
	return (count);
}

int	taken_fork(t_table *table, int philo_id)
{
	if (philo_id == table->number_of_philos && table->number_of_philos != 1)
	{
		if (table->fork[0] == 0 && table->fork[philo_id - 1] == 0)
		{
			table->fork[0] = philo_id;
			table->fork[philo_id - 1] = philo_id;
			printf("%ld %d has taken a fork\n", timestamp_ms(table->timestamp), philo_id);
			return (SUCCESS);
		}
		else
			return (FAILURE);
	}
	else
	{
		if (table->fork[philo_id - 1] == 0 && table->fork[philo_id] == 0)
		{
			table->fork[philo_id - 1] = philo_id;
			table->fork[philo_id] = philo_id;
			printf("%ld %d has taken a fork\n", timestamp_ms(table->timestamp), philo_id);
			return (SUCCESS);
		}
		else
			return (FAILURE);
	}
}

void	return_fork(t_table *table, int philo_id)
{
	int i;

	i = 0;
	while (i < table->number_of_philos)
	{
		if (table->fork[i] == philo_id)
			table->fork[i] = 0;
		i++;
		if (table->number_of_philos == 1)
			table->fork[i] = 0;
	}
}