/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:44 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/12 13:33:28 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ini_ph(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->philo_num)
	{
		vars->philo_vars[i].diet_times = 0;
		vars->philo_vars[i].pos = i + 1;
		vars->philo_vars[i].ffork = i;
		vars->philo_vars[i].sfork = (i + 1) % vars->philo_num;
		vars->philo_vars[i].vars = vars;
		i++;
	}
}

int	ini_mu(t_vars *vars)
{
	vars->mutex_i = 0;
	while (vars->mutex_i < vars->philo_num)
	{
		if (pthread_mutex_init(&(vars->forks[vars->mutex_i]), NULL))
			break ;
		vars->mutex_i++;
	}
	if (vars->mutex_i != vars->philo_num)
		return (ft_error(vars, mutex_error));
	if (pthread_mutex_init(&vars->meal, NULL))
		return (ft_error(vars, mutex_error));
	if (pthread_mutex_init(&vars->print, NULL))
		return (ft_error(vars, mutex_error2));
	ini_ph(vars);
	return (start_threads(vars));
}

int	philo_allocation(t_vars *vars)
{
	vars->philo_vars = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->philo_vars)
		return (ft_error(NULL, malloc_error));
	vars->forks = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->forks)
		return (ft_error(vars, malloc_error2));
	return (ini_mu(vars));
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
	if (vars.philo_num < 2 || vars.time2die < 0 || vars.time2eat < 0
		|| vars.time2sleep < 0)
		return (-1);
	else
		return (philo_allocation(&vars));
}

int	philo_ini(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
			return (ft_error(NULL, arg_error));
		i++;
	}
	if (philo_set_vars(ac, av) == -1)
		return (ft_error(NULL, arg_error));
	return (philo_set_vars(ac, av));
}

int	main(int ac, char **av)
{
	if (ac > 4 && ac < 7)
		return (philo_ini(ac, av));
	else
		return (ft_error(NULL, arg_error));
}
