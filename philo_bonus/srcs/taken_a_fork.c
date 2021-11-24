/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:20:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 21:20:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int taken_a_fork(t_philo *philo)
{
    if (philo->table->number_of_philos == 1)
    {
        ft_print(philo->table, philo->id, "has taken a fork");
        while (philo->died == 0)
            usleep(10);
        return (1);
    }
    sem_wait(philo->table->sem_fork);
    ft_print(philo->table, philo->id, "has taken a fork");
    sem_wait(philo->table->sem_fork);
    ft_print(philo->table, philo->id, "has taken a fork");
    return (philo->died);
}