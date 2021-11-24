/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:47:26 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 20:36:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int thinking(t_philo *philo)
{
    ft_print(philo->table, philo->id, "is thinking");
    return (philo->table->number_of_philos - *(int *)philo->table->alive_philos);
}