/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:38 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:31:49 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philosophers_init(t_table *table)
{
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (table->philos == NULL)
		exit_to_error(table, "malloc error");
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].eat_count = 0;
		table->philos[i].died = 0;
		table->philos[i].ate = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->philos[i].mutex_protect, NULL))
			exit_to_error(table, "mutex init error");
	}
}

void	philosophers_doing(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000 * philo->table->time_to_eat);
	if (pthread_create(&philo->observer_id, NULL, pthread_observer, philo))
		exit_to_error(philo->table, "pthread create error");
	if (pthread_detach(philo->observer_id))
		exit_to_error(philo->table, "pthread detach error");
	gettimeofday(&philo->last_eat_time, NULL);
	while (philo->table->someone_died == 0)
	{
		if (taken_a_fork(philo) != 0)
			break ;
		if (eating(philo) != 0)
			break ;
		if (sleeping(philo) != 0)
			break ;
		if (thinking(philo) != 0)
			break ;
	}
	if (philo->died)
		exit(EXIT_SUCCESS);
	if (philo->ate)
		exit(EXIT_FAILURE);
}
