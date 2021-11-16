/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:19 by bahn              #+#    #+#             */
/*   Updated: 2021/11/16 16:06:57 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long timestamp_ms(t_timestamp *timestamp)
{
    gettimeofday(&timestamp->end, NULL);
    return (((timestamp->end.tv_sec - timestamp->start.tv_sec) * 1000) + \
            (timestamp->end.tv_usec / 1000 - timestamp->start.tv_usec / 1000));
}