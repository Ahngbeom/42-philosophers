/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:29:52 by bahn              #+#    #+#             */
/*   Updated: 2021/12/02 13:11:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_table *table)
{
	int	i;

	if (table->philos != NULL)
	{
		i = -1;
		while (++i < table->number_of_philos)
		{
			pthread_mutex_destroy(&table->fork_mutex[i]);
			pthread_mutex_destroy(&table->philos[i].died_mutex);
			table->philos[i].table = NULL;
		}
		pthread_mutex_destroy(&table->print_mutex);
		free(table->philos);
	}
	free(table->fork_mutex);
	free(table);
}
