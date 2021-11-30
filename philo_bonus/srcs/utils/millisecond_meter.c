/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   millisecond_meter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:20:17 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 15:22:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int millisecond_meter(void)
{
    struct timeval timestamp;
    
    gettimeofday(&timestamp, NULL);
    return (timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000);
}