/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by bahn              #+#    #+#             */
/*   Updated: 2021/11/09 12:53:40 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo, int limit)
{
	t_timestamp pthread_ts;

	
	// if (philo->time_to_die < limit)
	// {
	// 	printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
	// 	return ;
	// }
	gettimeofday(&pthread_ts.start, NULL);
	while (timestamp_ms(&pthread_ts) < limit)
	{	
		if (death_check_philosophers(philo->table) == 1)
		{
			return ;
		}
		usleep(1000);
		philo->time_to_die--;
	}
	printf("%ld %d is eating\n", timestamp_ms(philo->table->timestamp), philo->id);
	philo->must_eat--;
	return_fork(philo->table, philo->id);
	sleeping(philo, philo->table->time_to_sleep);
}

void	sleeping(t_philo *philo, int limit)
{
	t_timestamp pthread_ts;

	if (death_check_philosophers(philo->table) == 1)
	{
		return ;
	}
	if (philo->time_to_die < limit)
	{
		printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
		return ;
	}
	gettimeofday(&pthread_ts.start, NULL);
	while (timestamp_ms(&pthread_ts) < limit)
	{
		usleep(1000);
		philo->time_to_die--;
	}
	printf("%ld %d is sleeping\n", timestamp_ms(philo->table->timestamp), philo->id);
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	int fork;

	if (death_check_philosophers(philo->table) == 1)
	{
		return ;
	}
	pthread_mutex_lock(&mutex);
	fork = taken_fork(philo->table, philo->id);
	pthread_mutex_unlock(&mutex);
	if (fork == SUCCESS)
		eating(philo, philo->table->time_to_eat);
	else
	{	
		printf("%ld %d is thinking\n", timestamp_ms(philo->table->timestamp), philo->id);
		usleep(1000);
		philo->time_to_die--;
		thinking(philo);
	}
}