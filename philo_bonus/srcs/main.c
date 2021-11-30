/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 21:09:54 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    t_table table;
    char *test = malloc(100);

    test = "ASdasda";
    if (argc < 5 || argc > 6)
        exception("Invalid arguments");
    memset(&table, 0, sizeof(t_table));
    table_setting(&table, argc, argv);
    philosophers_init(&table);
    create_philos_process(&table);
    cleanup_table(&table);
    
    // while (1);
    system("leaks philo_bonus > leaks_result && cat leaks_result && rm -rf leaks_result");
    // system("ps -elf | grep philo_bonus");
    return (0);
}