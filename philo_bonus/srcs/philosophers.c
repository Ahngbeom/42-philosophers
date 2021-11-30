/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:38 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 16:12:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    philosophers_init(t_table *table)
{
    char    *sem_name;
    int i;

    table->philos = (t_philo *)malloc(sizeof(t_philo) * table->number_of_philos);
    if (table->philos == NULL)
        exit(EXIT_FAILURE);
    i = -1;
    while (++i < table->number_of_philos)
    {
        table->philos[i].id = i + 1;
        table->philos[i].last_eat_time = 0;
        table->philos[i].eat_count = 0;
        table->philos[i].table = table;
        sem_name = ft_strjoin("/protect_", ft_itoa(table->philos[i].id));
        table->philos[i].sem_protect = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
        free(sem_name);
    }
}

static  void    *pthread_observer(void *data)
{
    t_philo *philo;

    philo = data;
    while (philo->table->someone_died == 0)
    {
        sem_wait(philo->sem_protect);
        if (millisecond_meter() - philo->last_eat_time >= philo->table->time_to_die)
        {
            sem_wait(philo->table->sem_status);
            protected_printf(philo->table, philo->id, "died");
            philo->table->someone_died++;
            sem_post(philo->table->sem_died);
            sem_post(philo->sem_protect);
            break ;
        }
        sem_post(philo->sem_protect);
        usleep(100);
    }
    return (philo);
}

void    philosophers_doing(t_philo *philo)
{
    philo->last_eat_time = millisecond_meter();
    pthread_create(&philo->observer_id, NULL, pthread_observer, philo);
    pthread_detach(philo->observer_id);
    if (philo->id % 2 == 0)
        usleep(1000);
    while (philo->table->someone_died == 0)
    {
        eating(philo);
        if (philo->table->must_eat != -1 && \
            philo->eat_count == philo->table->must_eat)
            sem_post(philo->table->sem_ate);
        if (philo->table->someone_died != 0)
            break ;
        sleeping(philo);
        if (philo->table->someone_died != 0)
            break ;
        thinking(philo);
        if (philo->table->someone_died != 0)
            break ;
    }
}