/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:55:23 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 17:04:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, s1_len + 1);
	ft_strlcat(ptr, (char *)s2, s1_len + s2_len + 1);
	return (ptr);
}
