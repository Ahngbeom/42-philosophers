/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:57 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 02:51:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	sleeping(t_philo *philo)
{
	t_timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	protected_printf(philo->table, philo->id, "is sleeping");
	while (philo->table->someone_died == 0 && \
			timems_meter(&timestamp) <= philo->table->time_to_sleep)
		usleep(1000);
	return (philo->table->someone_died);
}
