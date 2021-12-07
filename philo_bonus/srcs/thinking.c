/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:49:06 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 13:43:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	thinking(t_philo *philo)
{
	protected_printf(philo->table, philo->id, "is thinking");
	usleep(1000);
	return (philo->table->someone_died);
}
