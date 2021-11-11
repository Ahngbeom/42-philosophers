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

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->mutex[philo->id - 1]));
	pthread_mutex_lock(&(philo->table->mutex[philo->id % philo->table->number_of_philos]));
	printf("%ld %d has taken a fork\n", timestamp_ms(philo->table->timestamp), philo->id);

	printf("%ld %d is eating\n", timestamp_ms(philo->table->timestamp), philo->id);
	gettimeofday(&philo->timestamp->start, NULL);
	while (timestamp_ms(philo->timestamp) <= philo->table->time_to_eat)
	{	
		if (death_check_philosophers(philo->table) == 1)
		{
			return ;
		}
		usleep(1000);
		if(++(philo->life) >= philo->table->time_to_die)
		{
			printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
			exit(EXIT_FAILURE);
		}
	}
	philo->must_eat--;
	philo->life = 0;
	pthread_mutex_unlock(&(philo->table->mutex[philo->id - 1]));
	pthread_mutex_unlock(&(philo->table->mutex[philo->id % philo->table->number_of_philos]));
	sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", timestamp_ms(philo->table->timestamp), philo->id);
	gettimeofday(&philo->timestamp->start, NULL);
	while (timestamp_ms(philo->timestamp) <= philo->table->time_to_sleep)
	{
		usleep(1000);
		if(++(philo->life) >= philo->table->time_to_die)
		{
			printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
			exit(EXIT_FAILURE);
		}
	}
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	// int fork;

	printf("%ld %d is thinking\n", timestamp_ms(philo->table->timestamp), philo->id);

	// taken_fork(philo->table, philo->id);
	eating(philo);
	// else
	// {	
	// 	usleep(1000);
	// 	if(++(philo->life) >= philo->table->time_to_die)
	// 	{
	// 		printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	thinking(philo);
	// }
}