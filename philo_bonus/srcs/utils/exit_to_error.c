/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_to_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:22:54 by bahn              #+#    #+#             */
/*   Updated: 2021/12/07 14:07:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	exit_to_error(t_table *table, char *message)
{
	if (table != NULL)
		cleanup_table(table);
	printf("Error : %s\n", message);
	exit(EXIT_FAILURE);
}
