/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:04 by bahn              #+#    #+#             */
/*   Updated: 2021/11/25 20:48:43 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    semaphore_init_on_table(t_table *table, int must_eat)
{
    sem_unlink("alive_philos");
    sem_unlink("fork");
    sem_unlink("print");
    sem_unlink("terminate");
    sem_unlink("eat_finished_philos");
    table->alive_philos = sem_open("alive_philos", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    table->sem_fork = sem_open("fork", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    table->sem_print = sem_open("print", O_CREAT | O_EXCL, 0777, 1);
    table->terminate = sem_open("terminate", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    if (must_eat == -1)
        table->eat_finished_philos = NULL;
    else
        table->eat_finished_philos = sem_open("eat_finished_philos", O_CREAT | O_EXCL, 0777, table->number_of_philos);
    // system("ls /dev/shm"); //Linux
    // system("ls /dev/sem"); // Mac ?
}