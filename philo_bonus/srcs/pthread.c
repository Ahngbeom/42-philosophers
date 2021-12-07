/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:21:43 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:15:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	int	must_eat_checker(int must_eat, int eat_count)
{
	if (must_eat != 0 && eat_count >= must_eat)
		return (1);
	else
		return (0);
}

void	*pthread_observer(void *data)
{
	t_philo	*philo;

	philo = data;
	while (philo->table->someone_died == 0)
	{
		pthread_mutex_lock(&philo->mutex_protect);
		if (must_eat_checker(philo->table->must_eat, philo->eat_count))
			break ;
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
	if (philo->died)
		exit(EXIT_SUCCESS);
	if (philo->ate)
		exit(EXIT_FAILURE);
	return (philo);
}
