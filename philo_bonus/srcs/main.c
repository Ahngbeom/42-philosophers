/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 16:14:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    t_table table;

    if (argc < 5 || argc > 6)
        exit(EXIT_FAILURE);
    memset(&table, 0, sizeof(t_table));
    table_setting(&table, argc, argv);
    philosophers_init(&table);
    create_philos_process(&table);
    // system("leaks philo_bonus > leaks_result && cat leaks_result | grep leaked && rm -rf leaks_result");
    return (0);
}