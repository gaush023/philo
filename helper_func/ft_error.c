/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:09:38 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/12 13:40:23 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	byebye_mutex(t_vars *vars, enum e_error i)
{
	while (vars->mutex_i > 0)
	{
		pthread_mutex_destroy(&(vars->forks[i]));
		--vars->mutex_i;
	}
	if (i <= mutex_error2)
		pthread_mutex_destroy(&(vars->meal));
	else if (i < mutex_error2)
		pthread_mutex_destroy(&(vars->print));
}

void	delete_malloc(t_vars *vars, enum e_error i)
{
	if (i < malloc_error2)
		free(vars->forks);
	free(vars->philo_vars);
}

int	ft_error(t_vars *vars, enum e_error i)
{
	if (i == arg_error)
		write(2, "Error: wrong argument\n", 22);
	else if (i == malloc_error)
		write(2, "Error: malloc failed\n", 21);
	else if (i == malloc_error2)
	{
		write(2, "Error: malloc failed\n", 21);
		delete_malloc(vars, i);
	}
	else if (i <= mutex_error)
	{
		write(2, "Error: mutex failed\n", 20);
		delete_malloc(vars, i);
		byebye_mutex(vars, i);
	}
	write(2, "\n", 1);
	return (-1);
}

// int main(int ar, char **av)
// {
//     if(ar != 2)
//         return (-1);
//     ft_error(av[1]);
// }