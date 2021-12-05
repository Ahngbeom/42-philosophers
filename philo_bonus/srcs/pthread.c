/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:21:43 by bahn              #+#    #+#             */
/*   Updated: 2021/12/05 14:47:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*pthread_someone_died(void *data)
{
	t_table	*table;

	table = data;
	sem_wait(table->sem_died);
	table->someone_died++;
	sem_post(table->sem_ate);
	return (table);
}

void	*pthread_allofus_ate(void *data)
{
	t_table	*table;
	int		i;

	table = data;
	i = -1;
	while (++i < table->number_of_philos)
	{
		sem_wait(table->sem_ate);
		if (table->someone_died != 0)
			return (table);
	}
	table->someone_died++;
	table->ate_all++;
	return (table);
}

void	*pthread_observer(void *data)
{
	t_philo	*philo;

	philo = data;
	while (philo->table->someone_died == 0)
	{
		sem_wait(philo->sem_protect);
		if (philo->table->someone_died == 0 && \
				ms_meter() - philo->last_eat_time >= philo->table->time_to_die)
		{
			sem_wait(philo->table->sem_preemptive);
			protected_printf(philo->table, philo->id, "died");
			philo->table->someone_died++;
			sem_post(philo->table->sem_died);
			sem_post(philo->sem_protect);
			break ;
		}
		sem_post(philo->sem_protect);
		usleep(1000);
	}
	return (philo);
}
