/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timems_meter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:20:17 by bahn              #+#    #+#             */
/*   Updated: 2021/12/06 11:06:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	timems_meter(t_timeval *time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - time->tv_sec) * 1000) \
				+ ((now.tv_usec - time->tv_usec) / 1000));
}
