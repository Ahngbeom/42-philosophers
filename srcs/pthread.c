/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by bahn              #+#    #+#             */
/*   Updated: 2021/11/01 14:12:06 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pthreading(t_table *table)
{
	int i;

	gettimeofday(&table->ts_start, NULL);
	pthread_mutex_init(&table->mutex_lock, NULL);
	// while (1)
	// {
	// 	i = 0;
	// 	while (i < table->number_of_philosophers)
	// 	{
	// 		if (taken_fork(table, table->philos[i]->id) == TRUE)
	// 			pthread_create(&table->philos[i]->pth_id, NULL, pthread_eating, table->philos[i]);
	// 		// else if (table->philos[i]->flag_slept == 0)
	// 		else
	// 			pthread_create(&table->philos[i]->pth_id, NULL, pthread_sleeping, table->philos[i]);
	// 		// else
	// 		// 	pthread_create(&table->philos[i]->pth_id, NULL, pthread_thinking, table->philos[i]);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	while (i < table->number_of_philosophers)
	// 	{
	// 		pthread_join(table->philos[i]->pth_id, (void **)&table->philos[i]->pthread_status);
	// 		i++;
	// 	}
	// }

	while (1)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			if (taken_fork(table, table->philos[i]->id) == TRUE)
			{
				pthread_create(&table->philos[i]->pth_id, NULL, pthread_eating, table->philos[i]);
			}
			// else if (table->philos[i]->flag_slept == 0)
			else
				pthread_create(&table->philos[i]->pth_id, NULL, pthread_sleeping, table->philos[i]);
			// else
			// 	pthread_create(&table->philos[i]->pth_id, NULL, pthread_thinking, table->philos[i]);
			i++;
		}
		i = 0;
		while (i < table->number_of_philosophers)
		{
			pthread_join(table->philos[i]->pth_id, NULL);
			i++;
		}
	}
	
	
	
	// pthread_create(&table->philos[0]->pth_id, NULL, pthread_eating, table->philos[0]);
	// pthread_create(&table->philos[1]->pth_id, NULL, pthread_sleeping, table->philos[1]);
	// pthread_create(&table->philos[2]->pth_id, NULL, pthread_thinking, table->philos[2]);
	// pthread_join(table->philos[0]->pth_id, NULL);
	// pthread_join(table->philos[1]->pth_id, NULL);
	// pthread_join(table->philos[2]->pth_id, NULL);
	
}

void	*pthread_eating(void *data)
{
	int lapse_ms;

	pthread_mutex_lock(&((t_philo *)data)->table->mutex_lock);
	
	taken_fork(((t_philo *)data)->table, ((t_philo *)data)->id);
	gettimeofday(&((t_philo *)data)->table->ts_end, NULL);
	printf("%dms : [%d] has taken a fork (사용 가능 포크 개수 : %d)\n", \
			timestamp_ms(((t_philo *)data)->table), \
			((t_philo *)data)->id, \
			count_fork(((t_philo *)data)->table->fork, ((t_philo *)data)->table->number_of_philosophers));

	gettimeofday(&((t_philo *)data)->ts_start, NULL);
	lapse_ms = 0;
	while (lapse_ms < ((t_philo *)data)->table->time_to_eat)
	{
		death_check_philosophers(((t_philo *)data)->table);
		usleep(1000);
		gettimeofday(&((t_philo *)data)->ts_end, NULL);
		lapse_ms = (((t_philo *)data)->ts_end.tv_usec - ((t_philo *)data)->ts_start.tv_usec) / 1000;
		((t_philo *)data)->time_to_die--;
		printf("%dms : [%d] is eating\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
	}
	return_fork(((t_philo *)data)->table, ((t_philo *)data)->id);
	queue_rotate(((t_philo *)data)->table->queue, ((t_philo *)data)->table->number_of_philosophers);
	table_status(((t_philo *)data)->table);
	pthread_mutex_unlock(&((t_philo *)data)->table->mutex_lock);
	return (data);
}

void	*pthread_sleeping(void *data)
{
	int lapse_ms;

	gettimeofday(&((t_philo *)data)->ts_start, NULL);
	lapse_ms = 0;
	while (lapse_ms < ((t_philo *)data)->table->time_to_sleep)
	{
		death_check_philosophers(((t_philo *)data)->table);
		usleep(1000);
		gettimeofday(&((t_philo *)data)->ts_end, NULL);
		lapse_ms = (((t_philo *)data)->ts_end.tv_usec - ((t_philo *)data)->ts_start.tv_usec) / 1000;
		((t_philo *)data)->time_to_die--;
		printf("%dms : [%d] is sleeping\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
	}
	// ((t_philo *)data)->time_to_die -= ((t_philo *)data)->table->time_to_sleep;
	// ((t_philo *)data)->pthread_status[0] += 1;
	// table_status(((t_philo *)data)->table);

	return (data);
}

void	*pthread_thinking(void *data)
{
	while (1)
	{
		if (taken_fork(((t_philo *)data)->table, ((t_philo *)data)->id) == TRUE)
			break;
		usleep(1000);
		printf("%dms : [%d] is thinking\n", timestamp_ms(((t_philo *)data)->table), ((t_philo *)data)->id);
		((t_philo *)data)->time_to_die--;
	}
	// ((t_philo *)data)->pthread_status[0] = 0;
	return (data);
}
