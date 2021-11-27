/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/27 13:42:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    t_table *table;

    if (argc < 5 || argc > 6)
        ft_exception("Insufficient or excessive argument are present");
    table = table_setting(argc, argv);
    if (philosophers_doing(table) == PARENT_PROC)
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
        ft_free(table);
        // system("leaks philo_bonus > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    }
    return (0);
}