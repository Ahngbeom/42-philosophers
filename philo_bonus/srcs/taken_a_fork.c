/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:44:47 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 14:08:46 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int taken_a_fork(t_philo *philo)
{
    sem_wait(philo->table->sem_fork);
    protected_printf(philo->table, philo->id, "taken a fork");
    sem_wait(philo->table->sem_fork);
    protected_printf(philo->table, philo->id, "taken a fork");
    return (philo->table->someone_died);
}