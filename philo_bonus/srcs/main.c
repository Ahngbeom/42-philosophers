/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:51:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || argc > 6)
		exception("Invalid arguments");
	table_setting(&table, argc, argv);
	philosophers_init(&table);
	philosophers_on_process(&table);
	cleanup_table(&table);
	return (0);
}
