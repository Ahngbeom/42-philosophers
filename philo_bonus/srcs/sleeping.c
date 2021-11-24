/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:43:49 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 20:36:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int sleeping(t_philo *philo)
{
    ft_print(philo->table, philo->id, "is sleeping");
    philo->timestamp = time_ms();
    while (time_ms() - philo->timestamp <= philo->table->time_to_sleep)
        usleep(1000);
    return (philo->table->number_of_philos - *(int *)philo->table->alive_philos);
}