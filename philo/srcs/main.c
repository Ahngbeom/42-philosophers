/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/12/02 15:20:49 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		ft_exception("Insufficient or excessive argument are present");
	table = table_setting(argc, argv);
	if (table == NULL)
		ft_error(table, "malloc error");
	table->philos = philosophers_init(table);
	if (table->philos == NULL)
		ft_error(table, "malloc error");
	philosophers_doing(table);
	ft_free(table);
	return (0);
}
