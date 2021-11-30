/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:22:54 by bahn              #+#    #+#             */
/*   Updated: 2021/11/30 16:27:02 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    error(t_table *table, char *message)
{
    printf("Error : %s", message);
    cleanup_table(table);
    exit(EXIT_FAILURE);
}