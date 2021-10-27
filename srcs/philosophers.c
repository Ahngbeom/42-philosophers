/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/10/27 15:46:08 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_init(t_table *table, int time_to_die, int must_eat)
{
	int id;

	table->philos = malloc(sizeof(t_philo *) * (table->number_of_philosophers + 1));
	if (table->philos == NULL)
		exit(EXIT_FAILURE);
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->philos[id] = malloc(sizeof(t_philo));
		table->philos[id]->table = table;
		table->philos[id]->id = id + 1;
		table->philos[id]->time_to_die = time_to_die;
		table->philos[id]->must_eat = must_eat;
		id++;
	}
	table->philos[id] = NULL;
}

t_philo *create_philosopher(int id, int time_to_die, int must_eat)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(EXIT_FAILURE);
	philo->id = id;
	philo->time_to_die = time_to_die;
	philo->must_eat = must_eat;
	return (philo);
}

