/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:04 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 12:28:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

sem_t   **fork_init(int count)
{
    sem_t   **sem_fork;
    int i;

    sem_fork = malloc(sizeof(sem_t *) * count);
    i = -1;
    while (++i < count)
    {
        sem_fork[i] = sem_open(ft_strjoin("fork_", ft_itoa(i)), O_CREAT, 0777, 1);
    }
    return (sem_fork);
}

void    fork_remove(t_table *table)
{
    int i;

    i = -1;
    while (++i < table->number_of_philos)
    {
        sem_close(sem_fork[i]);
        sem_unlink(ft_strjoin("fork_", ft_itoa(i)));
    }
    system("ls /dev/shm");
}