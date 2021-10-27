/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:06:46 by bahn              #+#    #+#             */
/*   Updated: 2021/10/27 17:28:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	timestamp_ms(t_table *table)
{
	gettimeofday(&table->ts_end, NULL);
	return ((table->ts_end.tv_usec - table->ts_start.tv_usec) / 1000);
}