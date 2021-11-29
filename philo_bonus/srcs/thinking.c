/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:47:26 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 20:02:28 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int thinking(t_philo *philo)
{
    ft_print(philo->table, philo->id, "is thinking");
    return (philo->died);
}