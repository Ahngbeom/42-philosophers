/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:04 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 13:34:55 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    semaphore_init_on_table(t_table *table)
{
    sem_unlink("fork");
    table->sem_fork = sem_open("fork", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    sem_unlink("print");
    table->sem_print = sem_open("print", O_CREAT | O_EXCL, 0777, 1);
    sem_unlink("status");
    table->sem_status = sem_open("status", O_CREAT | O_EXCL, 0777, 1);
    sem_unlink("died");
    table->sem_died = sem_open("died", O_CREAT | O_EXCL, 0777, 0);
    if (table->must_eat != -1)
    {
        sem_unlink("ate");
        table->sem_ate = sem_open("ate", O_CREAT | O_EXCL, 0777, 0);
    }
    system("ls /dev/shm"); // Linux. But MacOS is not create /dev/shm directory
}