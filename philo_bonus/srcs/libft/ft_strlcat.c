/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:56:26 by bahn              #+#    #+#             */
/*   Updated: 2021/12/01 17:04:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;

	i = 0;
	j = 0;
	dest_len = (size_t)ft_strlen(dest);
	if (dest_len > size)
		return (ft_strlen(src) + size);
	while (dest[i] != '\0')
		i++;
	while (j + dest_len + 1 < size && src[j] != '\0')
	{
		dest[i] = src[j++];
		i++;
	}
	dest[i] = '\0';
	return (dest_len + ft_strlen(src));
}
