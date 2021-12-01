/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:46:57 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 14:51:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int sleeping(t_philo *philo)
{
    philo->timestamp = millisecond_meter();
    protected_printf(philo->table, philo->id, "is sleeping");
    while (millisecond_meter() - philo->timestamp <= philo->table->time_to_sleep && \
            philo->table->someone_died == 0)
        usleep(10);
    return (philo->table->someone_died);
}