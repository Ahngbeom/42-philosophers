/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/10/23 01:18:46 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_init(int argc, char **argv, t_list *lst, int number_of_philos)
{
	int i;

	i = 0;
	while (++i <= number_of_philos)
	{
		if (i == 1)
			lst = ft_lstnew(create_philosopher(argc, argv, i));
		else
			ft_lstadd_back(&lst, ft_lstnew(create_philosopher(argc, argv, i)));
	}
	printf("Create Philosopher SUCCESS\n");
	philosopher_status(lst);
}


t_philo *create_philosopher(int argc, char **argv, int id)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(EXIT_FAILURE);
	philo->id = id;
	philo->time_to_die = ft_atoi(argv[2]); //time_to_die;
	philo->time_to_eat = ft_atoi(argv[3]); //time_to_eat;
	philo->time_to_sleep = ft_atoi(argv[4]); //time_to_sleep;
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]); //must_eat;
	else
		philo->must_eat = -1;
	return (philo);
}

void	philosopher_status(t_list *philos)
{
	printf("철학자의 수 : %d\n", ft_lstsize(philos));
	printf("철학자들의 고유 번호 : %d, %d, %d\n", \
			((t_philo *)philos->content)->id, \
			((t_philo *)philos->next->content)->id, \
			((t_philo *)philos->next->next->content)->id);
	printf("철학자들의 남은 수명 : %dms, %dms, %dms\n", \
			((t_philo *)philos->content)->time_to_die, \
			((t_philo *)philos->next->content)->time_to_die, \
			((t_philo *)philos->next->next->content)->time_to_die);
	printf("철학자들의 남은 식사 시간 : %dms, %dms, %dms\n", \
			((t_philo *)philos->content)->time_to_eat, \
			((t_philo *)philos->next->content)->time_to_eat, \
			((t_philo *)philos->next->next->content)->time_to_eat);
	printf("철학자들의 남은 수면 시간 : %dms, %dms, %dms\n", \
			((t_philo *)philos->content)->time_to_sleep, \
			((t_philo *)philos->next->content)->time_to_sleep, \
			((t_philo *)philos->next->next->content)->time_to_sleep);
	printf("철학자들의 남은 식사 횟수 : %dms, %dms, %dms\n", \
			((t_philo *)philos->content)->must_eat, \
			((t_philo *)philos->next->content)->must_eat, \
			((t_philo *)philos->next->next->content)->must_eat);
	return ;
}