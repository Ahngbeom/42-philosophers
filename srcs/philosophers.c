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

	philo = malloc(sizeof(t_philo) * table->number_of_philos);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	
	i = 0;
	while (i < table->number_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].time_to_die = time_to_die;
		philo[i].must_eat = must_eat;
		philo[i].table = table;
		i++;
	}
	return (philo);
}
int	death_check_philosophers(t_table *table)
{
	int i;

	i = 0;
	while (i < table->number_of_philos)
	{
		if (table->pthread_id[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

// t_philo *create_philosopher(int id, int time_to_die, int must_eat)
// {
// 	t_philo *philo;

// 	philo = malloc(sizeof(t_philo));
// 	if (philo == NULL)
// 		exit(EXIT_FAILURE);
// 	philo->id = id;
// 	philo->time_to_die = time_to_die;
// 	philo->must_eat = must_eat;
// 	return (philo);
// }

