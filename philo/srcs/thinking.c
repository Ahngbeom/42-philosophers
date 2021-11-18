/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 13:01:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int thinking(t_philo *philo)
{
    printf("%d %d is thinking\n", timestamp_ms() - philo->table->timestamp, philo->id);
    if (philo->table->died_philosopher > 0)
        return (1);
    return (0);
}