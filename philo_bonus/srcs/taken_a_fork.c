/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:44:47 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 03:19:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	taken_a_fork(t_philo *philo)
{
	if (philo->table->number_of_philos == 1)
	{
		sem_wait(philo->table->sem_fork);
		protected_printf(philo->table, philo->id, "has taken a fork");
		while (philo->table->someone_died == 0)
			usleep(1000);
		sem_post(philo->table->sem_fork);
	}
	else
	{
		sem_wait(philo->table->sem_fork);
		protected_printf(philo->table, philo->id, "has taken a fork");
		sem_wait(philo->table->sem_fork);
		protected_printf(philo->table, philo->id, "has taken a fork");
	}
	return (philo->table->someone_died);
}
