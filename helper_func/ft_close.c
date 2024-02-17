/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:09:38 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 13:55:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	byebye_mutex(t_vars *vars, enum e_error i)
{
	while (vars->mutex_i > 0)
	{
		--vars->mutex_i;
		pthread_mutex_destroy(&(vars->forks[vars->mutex_i]));
	}
	if (i <= mutex_error2)
		pthread_mutex_destroy(&(vars->meal));
	if (i < mutex_error2)
		pthread_mutex_destroy(&(vars->print));
}

void	delete_malloc(t_vars *vars, enum e_error i)
{
	if (malloc_error2 == i )
		free(vars->forks);
	free(vars->philo_vars);
	if (i == close_success)
		free(vars->forks);
}

int	ft_close(t_vars *vars, enum e_error i)
{
	if (i == arg_error)
		write(2, "Error: wrong argument1\n", 23);
	else if (i == malloc_error)
		write(2, "Error: malloc failed2\n", 21);
	else if (i == malloc_error2)
	{
		write(2, "Error: malloc failed3\n", 21);
		delete_malloc(vars, i);
	}
	else if (i <= mutex_error && i >= mutex_error2)
	{
		write(2, "Error: mutex failed", 20);
		delete_malloc(vars, i);
		byebye_mutex(vars, i);
	}
	else if (i == thread_error)
	{
		write(2, "Error: thread failed\n", 21);
		delete_malloc(vars, i);
		byebye_mutex(vars, i);
	}
	else if (i == close_success)
	{
		delete_malloc(vars, i);
		byebye_mutex(vars, i);
		return (0);
	}
	return (-1);
}

// int main(int ar, char **av)
// {
//     if(ar != 2)
//         return (-1);
//     ft_close(av[1]);
// }