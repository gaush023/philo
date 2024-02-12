/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:24 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/12 13:38:19 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H_
# define PHILO_H_

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

enum				e_error
{
	arg_error = -1,
	malloc_error = -2,
	malloc_error2 = -3,
	mutex_error = -4,
	mutex_error2 = -5,
	thread_error = -6
};

typedef struct s_philo_vars
{
	int				diet_times;
	int				pos;
	int				ffork;
	int				sfork;
	pthread_t		id;
	struct s_vars	*vars;
}					t_philo_vars;

typedef struct s_vars
{
	int				philo_num;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				philo_must_eat;
	int				mutex_i;
	unsigned long	start_time;
	t_philo_vars	*philo_vars;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	print;
}					t_vars;

int					ft_atoi(char *s);
int					ft_error(t_vars *vars, enum e_error i);
size_t				ft_strlen(char *s);

int					start_threads(t_vars *vars);

#endif