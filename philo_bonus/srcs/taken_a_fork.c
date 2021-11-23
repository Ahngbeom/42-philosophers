/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:20:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:20:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int taken_a_fork(t_philo *philo)
{
    if (table->number_of_philos == 1)
    {
        ft_print(table, philo->id, "has taken a fork");
        while (died_philos == 0)
            usleep(10);
        return (1);
    }
    sem_wait(sem_fork[philo->id - 1]);
    ft_print(table, philo->id, "has taken a fork");
    sem_wait(sem_fork[philo->id % table->number_of_philos]);
    ft_print(table, philo->id, "has taken a fork");
    return (0);
}