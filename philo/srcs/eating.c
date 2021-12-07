/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:00:23 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->died_mutex);
	ft_printf(philo->table, philo->id, "is eating");
	gettimeofday(&philo->last_eat_time, NULL);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->died_mutex);
	while (timems_meter(philo->last_eat_time) <= philo->table->time_to_eat && \
			philo->table->ate_philos < philo->table->number_of_philos)
		usleep(100);
	pthread_mutex_unlock(\
		&philo->table->fork_mutex[philo->id % philo->table->number_of_philos] \
	);
	pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
	return (philo->table->died_philos);
}

int	must_eat_checker(t_table *table, t_philo *philo)
{
	if (table->must_eat == 0)
		return (0);
	else if (philo->eat_count < table->must_eat)
		return (0);
	else
	{
		philo->ate_it_all++;
		philo->table->ate_philos++;
		return (1);
	}
}
