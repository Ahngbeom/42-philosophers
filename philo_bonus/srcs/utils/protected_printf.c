/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:35:33 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 16:24:35 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	protected_printf(t_table *table, int philo_id, char *action)
{
	sem_wait(table->sem_print);
	printf("%d %d %s\n", \
			ms_meter() - table->begin_time, philo_id, action);
	sem_post(table->sem_print);
}
