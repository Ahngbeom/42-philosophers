/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:57 by bahn              #+#    #+#             */
/*   Updated: 2021/12/06 19:29:58 by bahn             ###   ########.fr       */
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
		usleep(100);
	return (philo->table->someone_died);
}
