/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 23:42:08 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    t_table *table;
    int whoami;
    // int state;
    int i;
    
    whoami = PARENT_PROC;
    table = table_setting(argc, argv);
    child_pid = malloc(sizeof(pid_t) * table->number_of_philos);
    
    i = -1;
    table->begin_time = time_ms();
    while (++i < table->number_of_philos)
    {
        child_pid[i] = fork();
        if (child_pid[i] == 0)
        {
            whoami = CHILD_PROC;
            table->philos[i].last_eat_time = time_ms();
            pthread_create(&table->philos[i].pthread_id, NULL, pthreadding, &table->philos[i]);
            pthread_create(&table->philos[i].observer_id, NULL, observer, &table->philos[i]);
            break;
        }
    }
    if (whoami == PARENT_PROC)
    {
        if (table->must_eat == -1)
        {
            while (*(int *)table->alive_philos > 0)
                usleep(10);
        }
        else
        {
            while (*(int *)table->eat_finished_philos > 0)
                usleep(10);
        }
        
        i = -1;
        while (++i < table->number_of_philos)
        {
            sem_close(table->philos[i].sem_died);
            sem_unlink(ft_strjoin("died_", ft_itoa(table->philos[i].id)));
        }
        sem_close(table->sem_fork);
        sem_close(table->sem_print);
        sem_close(table->terminate);
        sem_close(table->alive_philos);
        sem_close(table->eat_finished_philos);
        sem_unlink("fork");
        sem_unlink("print");
        sem_unlink("terminate");
        sem_unlink("alive_philos");
        sem_unlink("eat_finished_philos");
        free(child_pid);
        printf("Child process all terminate\n");
        // system("leaks philo_bonus > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    }
    else
    {
        pthread_join(table->philos[i].pthread_id, NULL);
        pthread_join(table->philos[i].observer_id, NULL);
        while (*(int *)table->alive_philos > 0)
            usleep(100);
    }
    return (0);
}