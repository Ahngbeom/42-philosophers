/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:27:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 16:34:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->died_mutex);
	ft_print(philo->table, philo->id, "is eating");
	philo->last_eat_time = time_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->died_mutex);
	while (time_ms() - philo->last_eat_time <= philo->table->time_to_eat)
		usleep(1000);
	pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
	pthread_mutex_unlock(\
		&philo->table->fork_mutex[philo->id % philo->table->number_of_philos] \
	);
	return (philo->table->died_philos);
}

int	must_eat_checker(t_table *table, t_philo *philo)
{
	if (table->must_eat == -1)
		return (0);
	else if (philo->eat_count < table->must_eat)
		return (0);
	else
	{
		philo->ate++;
		return (1);
	}
}
