/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/10/21 18:43:34 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_pthread(void)
{

}

int main(int argc, char const *argv[])
{
	pid_t pid;
	pthread_t pth_pid;

	pid = getpid();
	pth_pid = pthread_self();

	pthread_create(pth_pid, NULL, ft_pthread, argv[1]);

	return 0;
}
