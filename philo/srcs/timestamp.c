/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:19 by bahn              #+#    #+#             */
/*   Updated: 2021/11/18 12:35:04 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int timestamp_ms(void)
{
    struct timeval timestamp;

    gettimeofday(&timestamp, NULL);
    return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}