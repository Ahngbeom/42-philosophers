/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:25:34 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:10:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	semaphore_init(t_table *table)
{
	sem_unlink("/fork");
	table->sem_fork = \
			sem_open("/fork", O_CREAT | O_EXCL, 0777, table->number_of_philos);
	sem_unlink("/print");
	table->sem_print = sem_open("/print", O_CREAT | O_EXCL, 0777, 1);
	sem_unlink("/end");
	table->sem_end = sem_open("/end", O_CREAT | O_EXCL, 0777, 0);
}

void	semaphore_release(t_table *table)
{
	sem_close(table->sem_fork);
	sem_unlink("/fork");
	sem_close(table->sem_print);
	sem_unlink("/print");
	sem_post(table->sem_end);
	sem_close(table->sem_end);
	sem_unlink("/end");
}
