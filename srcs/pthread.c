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

void	*pthreading(void *data)
{
	t_philo *philo;

	philo = data;
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->table->died_philosopher == 0)
	{
		taken_fork(philo);
		if (eating(philo) == 1)
			break ;
		gettimeofday(&philo->last_eat_time->start, NULL);
		if (sleeping(philo) == 1)
			break ;
		thinking(philo);
	}
	return (data);
}

void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->fork_mutex[philo->id - 1]));
	if (philo->table->number_of_philos > 1)
		pthread_mutex_lock(&(philo->table->fork_mutex[philo->id % philo->table->number_of_philos]));
	else
		pthread_mutex_lock(&(philo->table->fork_mutex[philo->table->number_of_philos]));
	
	printf("%ld %d has taken a fork\n", timestamp_ms(philo->table->timestamp), philo->id);
	// eating(philo);
}

int	eating(t_philo *philo)
{
	printf("%ld %d is eating\n", timestamp_ms(philo->table->timestamp), \
											philo->id);
	gettimeofday(&philo->timestamp->start, NULL);
	while (timestamp_ms(philo->timestamp) <= philo->table->time_to_eat)
	{	
		// pthread_mutex_lock(&philo->table->die_check_mutex);
		// if (timestamp_ms(philo->last_eat_time) >= philo->table->time_to_die)
		// {	
		// 	if (philo->table->died_philosopher == 0)
		// 		printf("%ld %d is died\n", timestamp_ms(philo->table->timestamp), philo->id);
		// 	philo->table->died_philosopher++;
		// 	pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 1]));
		// 	pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id % philo->table->number_of_philos]));
		// 	pthread_mutex_unlock(&philo->table->die_check_mutex);
		// 	return ;
		// }
		// pthread_mutex_unlock(&philo->table->die_check_mutex);
		if (philo->table->died_philosopher > 0 || \
			timestamp_ms(philo->last_eat_time) >= philo->table->time_to_die)
		{
			philo->table->died_philosopher++;
			return (1);
		}
		usleep(10);
	}
	philo->must_eat--;
	pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id - 1]));
	pthread_mutex_unlock(&(philo->table->fork_mutex[philo->id % philo->table->number_of_philos]));
	// sleeping(philo);
	return (0);
}

int	sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", timestamp_ms(philo->table->timestamp), \
												philo->id);
	gettimeofday(&philo->timestamp->start, NULL);
	while (timestamp_ms(philo->timestamp) <= philo->table->time_to_sleep)
	{
		// pthread_mutex_lock(&philo->table->die_check_mutex);
		// if (philo->table->died_philosopher > 0)
		// {
		// 	pthread_mutex_unlock(&philo->table->die_check_mutex);
		// 	return ;
		// }
		// pthread_mutex_unlock(&philo->table->die_check_mutex);
		if (philo->table->died_philosopher > 0 || \
			timestamp_ms(philo->last_eat_time) >= philo->table->time_to_die)
		{
			philo->table->died_philosopher++;
			return (1);
		}
		usleep(10);
	}
	// thinking(philo);
	return (0);
}

void	thinking(t_philo *philo)
{
	// pthread_mutex_lock(&philo->table->die_check_mutex);
	// if (philo->table->died_philosopher > 0)
	// {
	// 	pthread_mutex_unlock(&philo->table->die_check_mutex);
	// 	return ;
	// }
	// pthread_mutex_unlock(&philo->table->die_check_mutex);

	printf("%ld %d is thinking\n", timestamp_ms(philo->table->timestamp), \
												philo->id);
	// taken_fork(philo);
}