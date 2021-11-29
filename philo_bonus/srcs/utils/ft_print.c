/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:22:07 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 20:03:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_print(t_table *table, int philo_id, char *action)
{
    sem_wait(table->sem_print);
    if (table->someone_died == 0)
        printf("%d %d %s\n", time_ms() - table->begin_time, philo_id, action);
    sem_post(table->sem_print);
}