/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:18:58 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 22:08:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	exception(char *message)
{
	printf("Exception : %s\n", message);
	exit(EXIT_FAILURE);
}

void	invalid_arguments_checker(t_table *table)
{
	if ((table->number_of_philos <= 0 || \
		table->number_of_philos > 200) || \
		table->time_to_die < 0 || \
		table->time_to_eat < 0 || \
		table->time_to_sleep < 0 || \
		table->must_eat < 0)
	{
		exception("Invalid arguments");
	}
}
