/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:48:49 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/10 03:46:48 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *s)
{
	long	i;
	int		flag;
	long	length;
	long	res;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
		return (-1);
	res = 0;
	flag = i;
	length = i;
	while (s[length] != '\0')
		length++;
	while (s[length - 1] == ' ')
		length--;
	i = flag;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (i != flag && length == i)
		return (res);
	else
		return (-1);
}

// int	main(int ar, char **av)
// {
// 	if (ar != 2)
// 		return (-1);
// 	printf("%d\n", ft_atoi(av[1]));
// 	return (0);
// }