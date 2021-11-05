/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:06:46 by bahn              #+#    #+#             */
/*   Updated: 2021/11/05 19:27:37 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	timestamp_ms(void)
{
	long int time;

	gettimeofday(&timestamp.end, NULL);
	time = (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000;
	printf("%ld - %ld = %ld\n", timestamp.end.tv_usec, timestamp.start.tv_usec, time);
	return (time);
}