/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:25:34 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 15:32:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    semaphore_init(t_table *table)
{
    sem_unlink("/fork");
    table->sem_fork = sem_open("/fork", O_CREAT, 0777, table->number_of_philos);
    sem_unlink("/print");
    table->sem_print = sem_open("/print", O_CREAT, 0777, 1);
    sem_unlink("/preemptive");
    table->sem_preemptive = sem_open("/preemptive", O_CREAT, 0777, 1);
    sem_unlink("/died");
    table->sem_died = sem_open("/died", O_CREAT, 0777, 0);
    sem_unlink("/ate");
    table->sem_ate = sem_open("/ate", O_CREAT, 0777, 0);
}