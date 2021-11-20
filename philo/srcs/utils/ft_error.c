/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:05:16 by bahn              #+#    #+#             */
/*   Updated: 2021/11/20 19:49:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_error(t_table *table, char *message)
{
    printf("Error >>> ");
    printf("%s\n", message);
    ft_free(table);
    exit(EXIT_FAILURE);
}