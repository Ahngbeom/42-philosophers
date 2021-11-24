/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:02:55 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 19:49:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo *philosophers_init(t_table *table)
{
    t_philo *philos;
    int i;

    philos = malloc(sizeof(t_philo) * table->number_of_philos);
    i = -1;
    while (++i < table->number_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].eat_count = 0;
        philos[i].table = table;
        sem_unlink(ft_strjoin("died_", ft_itoa(philos[i].id)));
        philos[i].sem_died = sem_open(ft_strjoin("died_", ft_itoa(philos[i].id)), O_CREAT | O_EXCL, 0777, 1);
        system("ls /dev/shm"); //Linux
        if (philos[i].sem_died == NULL)
            ft_error(table, "semaphore open");
        sem_wait(philos[i].table->terminate);
    }
    return (philos);
}