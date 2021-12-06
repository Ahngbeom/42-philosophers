/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:21:43 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 02:50:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*pthread_observer(void *data)
{
	t_philo	*philo;

	philo = data;
	while (philo->table->someone_died == 0)
	{
		pthread_mutex_lock(&philo->mutex_protect);
		if (philo->table->must_eat != 0 && \
			philo->eat_count >= philo->table->must_eat)
		{
			sem_post(philo->table->sem_end);
			break ;
		}
		if (timems_meter(&philo->last_eat_time) >= philo->table->time_to_die)
		{
			protected_printf(philo->table, philo->id, "died");
			philo->died++;
			philo->table->someone_died++;
			sem_post(philo->table->sem_end);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex_protect);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->mutex_protect);
	return (philo);
}
