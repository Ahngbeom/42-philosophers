/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/21 21:19:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
    t_table *table;
    
    if (argc < 5 || argc > 6)
        ft_exception("Insufficient or excessive argument are present");
    table = table_setting(argc, argv);
    if (argc == 5)
        table->philos = philosophers_init(table);
    else
        table->philos = philosophers_init(table);
    if (table->philos == NULL)
        ft_error(table, "malloc");
    philosophers_doing(table);
    ft_free(table);
    // system("leaks philo > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    return (0);
}