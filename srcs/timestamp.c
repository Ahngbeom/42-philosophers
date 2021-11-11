/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:06:46 by bahn              #+#    #+#             */
/*   Updated: 2021/11/08 12:27:49 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	timestamp_ms(t_timestamp *timestamp)
{
	long int time;

	gettimeofday(&timestamp->end, NULL);
	time = ((((timestamp->end.tv_sec - timestamp->start.tv_sec) * 1000000) + timestamp->end.tv_usec) - timestamp->start.tv_usec) / 1000;
	return (time);
}