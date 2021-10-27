/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:16:48 by bahn              #+#    #+#             */
/*   Updated: 2021/10/22 18:56:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_lst;

	if (lst == NULL)
		exit(EXIT_FAILURE);
	else
	{
		if (*lst)
		{
			last_lst = ft_lstlast(*lst);
			last_lst->next = new;
		}
		else
			*lst = new;
	}
}