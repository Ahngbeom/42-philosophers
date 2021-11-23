/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:05:16 by bahn              #+#    #+#             */
/*   Updated: 2021/11/22 21:13:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_error(t_table *table, char *message)
{
    // printf("Error >>> ");
    // printf("%s\n", message);
    (void)message;
    fprintf(stderr, "Error\n");
    ft_free(table);
    exit(EXIT_FAILURE);
}