/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:05:16 by bahn              #+#    #+#             */
/*   Updated: 2021/12/04 00:57:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(t_table *table, char *message)
{
	printf("Error >>> ");
	printf("%s\n", message);
	table_cleaning(table);
	exit(EXIT_FAILURE);
}
