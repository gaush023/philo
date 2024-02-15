/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:44:14 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/15 18:09:04 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_dead(t_vars *vars, t_philo_vars *philo_vars)
{
	int	i;

	while (!vars->max_mealstimes)
	{
		while (i < vars->philo_num && !vars->flag)
		{
			pthread_mutex_lock(&(vars->meal));
			if ((int )(get_time() - philo_vars[i].last_diet) >= vars->time2die)
			{
				vars->flag = 1;
				print_behavior("died", &philo_vars[i], LOCK);
			}
			pthread_mutex_unlock(&(vars->meal));
		}
		if (vars->flag)
			break ;
		i = 0;
		while (vars->must2eat && i < vars->philo_num
			&& philo_vars[i].diet_times >= vars->must2eat)
			i++;
		if (i == vars->philo_num)
			vars->max_mealstimes = 1;
	}
}
