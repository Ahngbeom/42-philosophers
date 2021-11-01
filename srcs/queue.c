/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:27:43 by bahn              #+#    #+#             */
/*   Updated: 2021/11/01 14:12:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_t	*queue_init(int size)
{
	pthread_t *queue;
	int i;

	queue = ft_calloc(sizeof(pthread_t), size);
	if (queue == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		queue[i] = i + 1;
		i++;
	}
	return (queue);
}

void	queue_status(pthread_t *queue, int size)
{
	int i;

	i = 0;
	printf("대기열 : [ ");
	while (i < size)
	{
		printf("%ld ", queue[i++]);
	}
	printf("]\n");
}

void	queue_rotate(pthread_t *queue, int size)
{
	pthread_t temp;
	int i;

	temp = queue[0];
	i = 1;
	while (i < size)
	{
		queue[i - 1] = queue[i];
		i++;
	}
	queue[i] = temp;
}