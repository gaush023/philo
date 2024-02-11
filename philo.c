/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:44 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/12 05:32:03 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ini_ph(t_vars *vars)
{
	int i;
	
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
	int	i;

	i = 0;
	while (i < vars->philo_num)
	{
		if (pthread_mutex_init(&(vars->forks[i]), NULL))
			break ;
		;
		i++;
	}
	if (i != vars->philo_num)
	{
		while (i > 0)
		{
			pthread_mutex_destroy(&(vars->forks[i]));
			--i;
		}
		return (-1);
	}
	if (pthread_mutex_init(&vars->meal, NULL))
	{
		while (i > 0)
		{
			pthread_mutex_destroy(&(vars->forks[i]));
			--i;
		}
		return (-1);
	}
	if (pthread_mutex_init(&vars->print, NULL))
	{
		while (i > 0)
		{
			pthread_mutex_destroy(&(vars->forks[i]));
			--i;
		}
		pthread_mutex_destroy(&(vars->meal));
	}
	return (0);
}

int	philo_allocation(t_vars *vars)
{
	vars->philo_vars = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->philo_vars)
		return (ft_error("Erorr"));
	vars->forks = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->forks)
	{
		free(vars->philo_vars);
		return (ft_error("Erorr"));
	}
	if (ini_mu(vars) == -1)
	{
		free(vars->philo_vars);
		free(vars->forks);
		return (ft_error("Erorr"));
	}
	ini_ph(&vars);
	return(start_threads(&vars));
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
		return (ft_error("Error: Invalid numbers"));
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
