/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:49:06 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:21:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	thinking(t_philo *philo)
{
	protected_printf(philo->table, philo->id, "is thinking");
	return (philo->table->someone_died);
}
