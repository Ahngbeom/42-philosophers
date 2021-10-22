/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/10/23 01:47:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	mutex_lock;
struct timeval timestamp_start;
struct timeval timestamp_end;

void	*ft_pthread(void *data)
{
	int	time;
	int diff;

	printf("%d\n", ((t_philo *)data)->id);

	pthread_mutex_lock(&mutex_lock);
	time = 0;
	diff = 0;
	while (time < 500)
	{
		usleep(1000);
		time++;
		gettimeofday(&timestamp_end, NULL);
		diff = (timestamp_end.tv_usec / 1000) - (timestamp_start.tv_usec / 1000);
		// printf("%d %d is eating\n", diff, ((t_philo *)data)->id);
		(void)diff;
		(void)data;
		// philosopher_status((t_list *)data);
	}
	pthread_mutex_unlock(&mutex_lock);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_list philos;

	if (argc < 5 || argc > 6)
	{
		printf("4개 또는 5개의 인자를 입력해주세요\n");
		printf("arg 1 : 철학자의 수 (number_of_philosophers): 테이블에 앉아 있는 철학자의 수와 포크의 수\n\n");
		printf("arg 2 : 철학자의 수명 (time_to_die): 밀리초 단위로, 철학자가 마지막으로 밥을 먹은 지 'time_to_die' 시간만큼이 지나거나, \
						프로그램 시작 후 'time_to_die' 시간만큼이 지나면 해당 철학자는 사망합니다.\n\n");
		printf("arg 3 : 밥을 먹는데 걸리는 시간 (time_to_eat) : 밀리초 단위로, 철학자가 밥을 먹는 데 걸리는 시간입니다. \
						해당 시간동안, 철학자는 두 개의 포크를 소유하고 있어야 합니다.\n\n");
		printf("arg 4 : 잠자는 시간 (time_to_sleep) : 밀리초 단위로, 잠을 자는 데 소모되는 시간입니다.\n\n");
		printf("[arg 5] : 각 철학자가 최소한 밥을 먹어야 하는 횟수 (number_of_times_each_philosopher_must_eat) : \
						해당 인자값은 선택사항입니다. \
						모든 철학자가 'number_of_times_each_philosopher_must_eat' 횟수만큼 밥을 먹었다면 시뮬레이션이 종료됩니다. \
						해당 값이 명시되어 있지 않다면, 철학자가 한 명이라도 사망할 때까지 시뮬레이션은 계속됩니다.\n\n");
		exit(EXIT_FAILURE);
	}
	else
		philosopher_init(argc, argv, &philos, ft_atoi(argv[1]));
		
	gettimeofday(&timestamp_start, NULL);

	pthread_mutex_init(&mutex_lock, NULL);
	printf("%d\n", ((t_philo *)philos.content)->id);
	pthread_create(&philos.pth_id, NULL, ft_pthread, philos.content);
	pthread_join(philos.pth_id, NULL);
	printf("%ld\n", philos.pth_id);

	gettimeofday(&timestamp_end, NULL);
	
	return 0;
}
