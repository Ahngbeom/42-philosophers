/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:27:43 by bahn              #+#    #+#             */
/*   Updated: 2021/11/02 21:41:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*queue_init(int size)
{
	int *queue;
	int i;

	queue = ft_calloc(sizeof(int), size);
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

void	queue_status(int *queue, int size)
{
	int i;

	i = 0;
	printf("대기열 : [ ");
	while (queue != NULL && i < size)
	{
		printf("%d ", queue[i++]);
	}
	printf("]\n");
}

void	queue_rotate(int *queue, int size)
{
	int temp;
	int i;

	temp = queue[0];
	// printf("first queue rotate : %d -> %d\n", temp, queue[1]);
	i = 0;
	while (i < size - 1)
	{
		queue[i] = queue[i + 1];
		i++;
	}
	queue[i] = temp;
}