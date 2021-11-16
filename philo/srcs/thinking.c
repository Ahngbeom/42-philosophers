/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 15:06:13 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int thinking(t_philo *philo)
{
    printf("%ld %d is thinking\n", timestamp_ms(philo->table->timestamp), philo->id);
    return (0);
}