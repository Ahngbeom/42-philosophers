/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/11/29 22:26:52 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int main(int argc, char *argv[])
{
    t_table *table;

    if (argc < 5 || argc > 6)
        ft_exception("Insufficient or excessive argument are present");
    table = table_setting(argc, argv);
    process_on_philosophers(table);
    ft_free(table);
    return (0);
}