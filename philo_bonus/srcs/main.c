/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/12/05 01:53:58 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || argc > 6)
		exception("Invalid arguments");
	memset(&table, 0, sizeof(t_table));
	table_setting(&table, argc, argv);
	philosophers_init(&table);
	philosophers_on_process(&table);
	cleanup_table(&table);
	return (0);
}
