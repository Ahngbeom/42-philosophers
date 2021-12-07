/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:32:43 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:10:30 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exception(char *message)
{
	printf("Exception : ");
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	invalid_arguments_checker(t_table *table)
{
	if ((table->number_of_philos <= 0 || \
		table->number_of_philos > 200) || \
		table->time_to_die <= 60 || \
		table->time_to_eat <= 60 || \
		table->time_to_sleep <= 60 || \
		table->must_eat < 0)
	{
		ft_exception("Invalid arguments");
	}
}
