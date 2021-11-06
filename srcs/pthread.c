/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by bahn              #+#    #+#             */
/*   Updated: 2021/11/07 00:43:35 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{	
		usleep(1000);
		gettimeofday(&timestamp.end, NULL);
		philo->time_to_die--;
		printf("%ld %d is eating\n", timestamp_ms(), philo->id);
	}
	philo->must_eat--;
	return_fork(philo->table, philo->id);
	sleeping(philo, philo->table->time_to_sleep);
}

void	sleeping(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{
		usleep(1000);
		gettimeofday(&timestamp.end, NULL);
		philo->time_to_die--;
		printf("%ld %d is sleeping\n", timestamp_ms(), philo->id);
	}
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	int fork;

	pthread_mutex_lock(&mutex);
	fork = taken_fork(philo->table, philo->id);
	pthread_mutex_unlock(&mutex);
	if (fork == SUCCESS)
		eating(philo, philo->table->time_to_eat);
	else
	{	
		usleep(1000);
		philo->time_to_die--;
		gettimeofday(&timestamp.end, NULL);
		printf("%ld %d is thinking\n", timestamp_ms(), philo->id);
		thinking(philo);
	}
}