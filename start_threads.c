/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:30:34 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/12 14:29:51 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *params)
{
    int i;
    t_philo_vars *philo_vars;
    t_vars *vars;

    i = 0;
    philo_vars = (t_philo_vars *)params;
    vars = philo_vars->vars;
    
}

unsigned long	get_time(void)
{
	struct timeval	time;

	getteimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

int	start_threads(t_vars *vars)
{
	int i;

	i = 0;
	vars->start_time = get_time();
	while (i < vars->philo_num)
	{
		if (pthread_create(&(vars->philo_vars[i].id), NULL, routine,
				&(vars->philo_vars[i])))
			return (ft_error(vars, thread_error));
	}
}