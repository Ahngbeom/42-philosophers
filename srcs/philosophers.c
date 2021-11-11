/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/11/03 22:33:29 by bahn             ###   ########.fr       */
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
		philo[i].life = 0;
		philo[i].must_eat = must_eat;
		philo[i].table = table;
		philo[i].timestamp = malloc(sizeof(t_timestamp));
		i++;
	}
	return (philo);
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

// void	death_check_philosophers(t_table *table)
// {
// 	int i;

// 	i = 0;
// 	while (i < table->number_of_philosophers)
// 	{
// 		if (table->philos[i]->time_to_die <= 0)
// 		{
// 			gettimeofday(&table->ts_end, NULL);
// 			i = 0;
// 			while (i < table->number_of_philosophers)
// 			{
// 				pthread_detach(table->philos[i++]->pth_id);
// 			}
// 			table_status(table);
// 			exit(EXIT_SUCCESS);
// 		}
// 		i++;
// 	}
// 	return ;
// }