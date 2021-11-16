/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/11/09 12:44:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philosopher_init(t_table *table, int time_to_die, int must_eat)
{
	t_philo *philo;
	int i;

	(void)time_to_die;
	philo = malloc(sizeof(t_philo) * table->number_of_philos);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	
	i = 0;
	while (i < table->number_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].must_eat = must_eat;
		philo[i].table = table;
		philo[i].timestamp = malloc(sizeof(t_timestamp));
		philo[i].last_eat_time = malloc(sizeof(t_timestamp));
		i++;
	}
	return (philo);
}

void	philosopher_doing(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->number_of_philos)
	{
		if (pthread_create(&table->philos[i].pthread_id, NULL, pthreading, &table->philos[i]))
		{
			printf("error\n");
			exit(1);
		}
	}
	while (1)
	{
		if (table->died_philosopher > 0)
			break;
	}
}

void	philosopher_end(t_table *table)
{
	int i;

	i = -1;
	while (++i < table->number_of_philos)
		pthread_join(table->philos[i].pthread_id, NULL);

	i = -1;
	while (++i < table->number_of_philos)
		pthread_mutex_destroy(&table->fork_mutex[i]);
	pthread_mutex_destroy(&table->die_check_mutex);
}
