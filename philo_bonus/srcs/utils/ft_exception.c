/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:32:43 by bahn              #+#    #+#             */
/*   Updated: 2021/11/22 21:13:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_exception(char *message)
{
    // printf("Exception : ");
    // printf("%s\n", message);
    (void)message;
    fprintf(stderr, "Error\n");
    exit(EXIT_FAILURE);
}