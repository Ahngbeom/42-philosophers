/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:49:56 by bahn              #+#    #+#             */
/*   Updated: 2021/11/08 12:27:51 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*set_table(int argc, char **argv)
{
	t_table *table;
	int i;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		exit(EXIT_FAILURE);
	table->number_of_philos = ft_atoi(argv[1]);
	if (table->number_of_philos == 1)
		table->fork = ft_calloc(sizeof(int), table->number_of_philos + 1);
	else
		table->fork = ft_calloc(sizeof(int), table->number_of_philos);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		table->philos = philosopher_init(table, ft_atoi(argv[2]), -1);
	else if (argc == 6)
		table->philos = philosopher_init(table, ft_atoi(argv[2]), ft_atoi(argv[5]));
	table->pthread_id = ft_calloc(sizeof(pthread_t), table->number_of_philos + 1);
	table->mutex = malloc(sizeof(pthread_mutex_t) * table->number_of_philos);
	i = 0;
	while (i < table->number_of_philos)
	{
		pthread_mutex_init(&table->mutex[i++], NULL);
	}
	table->timestamp = malloc(sizeof(t_timestamp));
	return (table);
}

void	table_status(t_table *table)
{
	int	i;

	printf("==================================================\n");
	// printf("pthread created : [ ");
	// i = -1;
	// while (++i < table->number_of_philos)
	// {
	// 	printf("%ld ", table->pthread_id[i]);
	// }
	// printf("]\n");
	printf("철학자의 수 : %d\n", table->number_of_philos);
	printf("철학자들의 식사 시간 : %dms\n", table->time_to_eat);
	printf("철학자들의 수면 시간 : %dms\n", table->time_to_sleep);
	printf("사용 가능 포크 개수 : %d\n", count_fork(table->fork, table->number_of_philos));
	// queue_status(table->queue, table->number_of_philos);
	i = -1;
	while (++i < table->number_of_philos)
	{
		printf("철학자 %d의 상태 (남은 수명, 남은 식사 횟수) : %d, %d\n", table->philos[i].id, table->philos[i].life, table->philos[i].must_eat);
	}
	printf("==================================================\n");
	return ;
}