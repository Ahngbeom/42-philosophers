/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:41:03 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:00:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*observer(void *data)
{
	t_philo	*philo;

	philo = data;
	while (philo->table->died_philos == 0 && philo->ate_it_all == 0)
	{
		pthread_mutex_lock(&philo->died_mutex);
		if (timems_meter(philo->last_eat_time) >= philo->table->time_to_die)
		{
			ft_printf(philo->table, philo->id, "died");
			philo->table->died_philos++;
			pthread_mutex_unlock(&philo->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->died_mutex);
		usleep(1000);
	}
	return (data);
}

void	*pthreadding(void *data)
{
	t_philo	*philo;

	philo = data;
	if (philo->id % 2 == 0)
		usleep(1000 * philo->table->time_to_eat);
	while (philo->table->died_philos == 0)
	{
		if (taken_a_fork(philo) != 0)
			break ;
		if (eating(philo) != 0 || must_eat_checker(philo->table, philo))
			break ;
		if (sleeping(philo) != 0)
			break ;
		if (thinking(philo) != 0)
			break ;
	}
	return (data);
}
