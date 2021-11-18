/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 19:20:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table table;

	if (argc < 5 || argc > 6)
		ft_exception();
	else
		set_table(&table, argc, argv);
	philosophers_running(&table);
	philosophers_stop(&table);
	ft_free(&table);
	system("leaks philo > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return 0;
}
