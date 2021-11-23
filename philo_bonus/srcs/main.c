/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:22:40 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    pid_t *child_pid;
    int whoami;
    int state;
    int i;
    
    whoami = PARENT_PROC;
    table = table_setting(argc, argv);
    child_pid = malloc(sizeof(pid_t) * table->number_of_philos);
    
    i = -1;
    died_philos = 0;
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
        i = -1;
        while (++i < table->number_of_philos)
            waitpid(child_pid[i], &state, 0);
        fork_remove(table);
        free(child_pid);
        printf("Child process all terminate\n");
        // system("leaks philo_bonus > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    }
    else
    {
        pthread_join(table->philos[i].pthread_id, NULL);
        pthread_join(table->philos[i].observer_id, NULL);
    }
    return (0);
}

// int main(int argc, char *argv[])
// {
//     t_table *table;
    
//     if (argc < 5 || argc > 6)
//         ft_exception("Insufficient or excessive argument are present");
//     table = table_setting(argc, argv);
//     if (argc == 5)
//         table->philos = philosophers_init(table);
//     else
//         table->philos = philosophers_init(table);
//     if (table->philos == NULL)
//         ft_error(table, "malloc");
//     philosophers_doing(table);
//     ft_free(table);
//     // system("leaks philo > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
//     return (0);
// }