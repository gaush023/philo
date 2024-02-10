/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:44 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/10 14:07:12 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_allocation(void)
{
	t_vars	;
}


int	philo_set_vars(int ac, char **av)
{
	t_vars	vars;

	vars.philo_num = ft_atoi(av[1]);
	vars.time2die = ft_atoi(av[2]);
	vars.time2eat = ft_atoi(av[3]);
	vars.time2sleep = ft_atoi(av[4]);
	if (ac == 6)
		vars.philo_must_eat = ft_atoi(av[5]);
	else
		vars.philo_must_eat = -1;
	if (vars.philo_num < 2 || vars.time2die < 0
		|| vars.time2eat < 0 || vars.time2sleep < 0)
		return (ft_error("Error: Invalid numbers"));
	else
		return (philo_allocation());
}

int	philo_ini(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
			return (ft_error("Error: Invalid numbers"));
		i++;
	}
	if (philo_set_vars(ac, av) == -1)
		return (ft_error("Error: Invalid numbers"));
	return (philo_set_vars(ac, av));
}

int	main(int ac, char **av)
{
	if (ac > 4 && ac < 7)
		return (philo_ini(ac, av));
	else
		return (ft_error("Error"));
}
