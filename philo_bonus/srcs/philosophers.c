/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:38 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 16:25:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philosophers_init(t_table *table)
{
	char	*sem_name;
	char	*id;
	int		i;

	table->philos = malloc(sizeof(t_philo) * table->number_of_philos);
	if (table->philos == NULL)
		exit_to_error(table, "malloc error");
	i = -1;
	while (++i < table->number_of_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_eat_time = 0;
		table->philos[i].eat_count = 0;
		table->philos[i].table = table;
		id = ft_itoa(table->philos[i].id);
		sem_name = ft_strjoin("/protect_", id);
		sem_unlink(sem_name);
		table->philos[i].sem_protect = sem_open(sem_name, O_CREAT, 0777, 1);
		free(id);
		free(sem_name);
	}
}

void	philosophers_doing(t_philo *philo)
{
	philo->last_eat_time = ms_meter();
	if (pthread_create(&philo->observer_id, NULL, pthread_observer, philo) != 0)
		exit_to_error(philo->table, "pthread create error");
	if (pthread_detach(philo->observer_id) != 0)
		exit_to_error(philo->table, "pthread detach error");
	if (philo->id % 2 == 0)
		usleep(1000);
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
}
