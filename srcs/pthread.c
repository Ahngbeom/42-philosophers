/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by bahn              #+#    #+#             */
/*   Updated: 2021/11/04 20:26:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{	
		usleep(1000);
		philo->time_to_die--;
	}
	philo->must_eat--;
	gettimeofday(&timestamp.end, NULL);
	printf("%ldms : [%d] is eating\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
	return_fork(philo->table, philo->id);
	sleeping(philo, philo->table->time_to_sleep);
}

void	sleeping(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{
		usleep(1000);
		philo->time_to_die--;
	}
	gettimeofday(&timestamp.end, NULL);
	printf("%ldms : [%d] is sleeping\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	if (taken_fork(philo->table, philo->id) == SUCCESS)
		eating(philo, philo->table->time_to_eat);
	else
	{	
		usleep(1000);
		philo->time_to_die--;
		gettimeofday(&timestamp.end, NULL);
		printf("%ldms : [%d] is thinking\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
		thinking(philo);
	}
}
// void	pthreading(t_table *table)
// {
// 	int i;

// 	gettimeofday(&table->ts_start, NULL);
// 	pthread_mutex_init(&table->mutex_lock, NULL);

// 	while (1)
// 	{
// 		i = 0;
// 		while (i < table->number_of_philosophers)
// 		{
// 			if (table->queue[0] == 0)
// 			{
// 				pthread_create(&table->philos[i]->pth_id, NULL, pthread_eating, table->philos[i]);
// 				*table->queue = table->philos[i]->pth_id;
// 			}
// 			else if (table->queue[0] == table->philos[i]->pth_id)
// 			{	
// 				pthread_create(&table->philos[i]->pth_id, NULL, pthread_eating, table->philos[i]);
// 			}
// 			else
// 			{
// 				pthread_create(&table->philos[i]->pth_id, NULL, pthread_sleeping, table->philos[i]);
// 				pthread_create(&table->philos[i]->pth_id, NULL, pthread_thinking, table->philos[i]);
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		while (i < table->number_of_philosophers)
// 		{
// 			pthread_join(table->philos[i]->pth_id, NULL);
// 			// pthread_detach(table->philos[i]->pth_id);
// 			i++;
// 		}
// 		table_status(table);
// 	}

// 	// pthread_create(&table->philos[0]->pth_id, NULL, pthread_eating, table->philos[0]);
// 	// pthread_create(&table->philos[1]->pth_id, NULL, pthread_sleeping, table->philos[1]);
// 	// pthread_join(table->philos[0]->pth_id, NULL);
// 	// pthread_join(table->philos[1]->pth_id, NULL);

// }

// void	*pthread_eating(void *data)
// {
// 	int lapse_ms;

// 	pthread_mutex_lock(&((t_philo *)data)->table->mutex_lock);
// 	taken_fork(((t_philo *)data)->table, ((t_philo *)data)->id);
// 	pthread_mutex_unlock(&((t_philo *)data)->table->mutex_lock);

// 	gettimeofday(&((t_philo *)data)->table->ts_end, NULL);
// 	printf("%dms : [%d] has taken a fork (사용 가능 포크 개수 : %d)\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id, count_fork(((t_philo *)data)->table->fork, ((t_philo *)data)->table->number_of_philosophers));

// 	gettimeofday(&((t_philo *)data)->ts_start, NULL);
// 	lapse_ms = 0;
// 	while (lapse_ms < ((t_philo *)data)->table->time_to_eat)
// 	{
// 		death_check_philosophers(((t_philo *)data)->table);
// 		usleep(1000);
// 		gettimeofday(&((t_philo *)data)->ts_end, NULL);
// 		lapse_ms = (((t_philo *)data)->ts_end.tv_usec - ((t_philo *)data)->ts_start.tv_usec) / 1000;
// 		((t_philo *)data)->time_to_die--;
// 		printf("%dms : [%d] is eating\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
// 	}
// 	return_fork(((t_philo *)data)->table, ((t_philo *)data)->id);
// 	queue_rotate(((t_philo *)data)->table->queue, ((t_philo *)data)->table->number_of_philosophers);
// 	// table_status(((t_philo *)data)->table);
// 	return (data);
// }

// void	*pthread_sleeping(void *data)
// {
// 	int lapse_ms;

// 	gettimeofday(&((t_philo *)data)->ts_start, NULL);
// 	lapse_ms = 0;
// 	while (lapse_ms < ((t_philo *)data)->table->time_to_sleep)
// 	{
// 		death_check_philosophers(((t_philo *)data)->table);
// 		usleep(1000);
// 		gettimeofday(&((t_philo *)data)->ts_end, NULL);
// 		lapse_ms = (((t_philo *)data)->ts_end.tv_usec - ((t_philo *)data)->ts_start.tv_usec) / 1000;
// 		((t_philo *)data)->time_to_die--;
// 		printf("%dms : [%d] is sleeping\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
// 	}
// 	// ((t_philo *)data)->time_to_die -= ((t_philo *)data)->table->time_to_sleep;
// 	// ((t_philo *)data)->pthread_status[0] += 1;
// 	// table_status(((t_philo *)data)->table);

// 	return (data);
// }

// void	*pthread_thinking(void *data)
// {
// 	while (1)
// 	{
// 		usleep(1000);
// 		printf("%dms : [%d] is thinking\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
// 		((t_philo *)data)->time_to_die--;
// 		if (taken_fork(((t_philo *)data)->table, ((t_philo *)data)->id) == SUCCESS)
// 			break;
// 	}
// 	// ((t_philo *)data)->pthread_status[0] = 0;
// 	return (data);
// }
