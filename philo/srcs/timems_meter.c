/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timems_meter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:29:12 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 15:00:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	timems_meter(struct timeval time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - time.tv_sec) * 1000) \
			+ ((now.tv_usec - time.tv_usec) / 1000));
}
