/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:49:56 by bahn              #+#    #+#             */
/*   Updated: 2021/11/01 13:40:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*set_table(int argc, char **argv)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		exit(EXIT_FAILURE);
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->fork = ft_calloc(sizeof(int), table->number_of_philosophers);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->queue = queue_init(table->number_of_philosophers);
	if (argc == 6)
		philosopher_init(table, ft_atoi(argv[2]), ft_atoi(argv[5]));
	else
		philosopher_init(table, ft_atoi(argv[2]), -1);
	return (table);
}

void	table_status(t_table *table)
{
	int	i;

	printf("철학자의 수 : %d\n", table->number_of_philosophers);
	printf("철학자들의 식사 시간 : %dms\n", table->time_to_eat);
	printf("철학자들의 수면 시간 : %dms\n", table->time_to_sleep);
	printf("사용 가능 포크 개수 : %d\n", count_fork(table->fork, table->number_of_philosophers));
	queue_status(table->queue, table->number_of_philosophers);
	i = -1;
	while (++i < table->number_of_philosophers)
	{
		printf("철학자 %d의 상태 (남은 수명, 남은 식사 횟수) : %d, %d\n", \
			table->philos[i]->id, \
			table->philos[i]->time_to_die, \
			table->philos[i]->must_eat);
	}
	return ;
}