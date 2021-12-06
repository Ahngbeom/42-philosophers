/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:35:33 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 02:12:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	protected_printf(t_table *table, int philo_id, char *action)
{
	sem_wait(table->sem_print);
	if (table->someone_died == 0)
		printf("%d %d %s\n", \
				timems_meter(&table->begin_time), philo_id, action);
	if (ft_strncmp("died", action, ft_strlen("died")) != 0)
		sem_post(table->sem_print);
}
