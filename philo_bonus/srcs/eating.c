/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:43:14 by bahn              #+#    #+#             */
/*   Updated: 2021/12/05 14:44:37 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	must_eat_checker(t_philo *philo)
{
	if (philo->table->must_eat != 0 && \
		philo->eat_count == philo->table->must_eat)
		sem_post(philo->table->sem_ate);
}

int	eating(t_philo *philo)
{
	sem_wait(philo->sem_protect);
	protected_printf(philo->table, philo->id, "is eating");
	philo->last_eat_time = ms_meter();
	philo->eat_count++;
	sem_post(philo->sem_protect);
	while ((philo->table->someone_died == 0 && \
			ms_meter() - philo->last_eat_time <= philo->table->time_to_eat))
		usleep(1000);
	sem_post(philo->table->sem_fork);
	sem_post(philo->table->sem_fork);
	must_eat_checker(philo);
	return (philo->table->someone_died);
}
