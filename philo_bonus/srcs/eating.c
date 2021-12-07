/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 13:53:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	int	must_eat_checker(t_philo *philo)
{
	if (philo->table->must_eat != 0 && \
		philo->eat_count == philo->table->must_eat)
	{
		philo->ate++;
		sem_post(philo->table->sem_end);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_protect);
	protected_printf(philo->table, philo->id, "is eating");
	gettimeofday(&philo->last_eat_time, NULL);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex_protect);
	while ((philo->table->someone_died == 0 && \
			timems_meter(&philo->last_eat_time) <= philo->table->time_to_eat))
		usleep(1000);
	sem_post(philo->table->sem_fork);
	sem_post(philo->table->sem_fork);
	return (philo->table->someone_died || must_eat_checker(philo));
}
