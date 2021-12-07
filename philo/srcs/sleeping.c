/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:43:49 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:00:26 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleeping(t_philo *philo)
{
	ft_printf(philo->table, philo->id, "is sleeping");
	gettimeofday(&philo->timestamp, NULL);
	while (timems_meter(philo->timestamp) <= philo->table->time_to_sleep && \
			philo->table->ate_philos < philo->table->number_of_philos)
		usleep(100);
	return (philo->table->died_philos);
}
