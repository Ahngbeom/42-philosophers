/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:22:07 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 23:42:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_print(t_table *table, int philo_id, char *action)
{
    sem_wait(table->sem_print);
    if (*(int *)table->alive_philos == table->number_of_philos)
        printf("%d %d %s\n", time_ms() - table->begin_time, philo_id, action);
    sem_post(table->sem_print);
}