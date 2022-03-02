/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:51:53 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/02 11:15:48 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	repeats(int ac, char **av)
{
	int	i;
	int	i2;
	int	val;

	i = 1;
	while (i < ac)
	{
		val = ft_atoi(av[i]);
		i2 = 1;
		while (i2 < ac)
		{
			if (ft_atoi(av[i2]) == val && i2 != i)
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

int	beyond_extremes(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > 2147483647 || ft_atoi(av[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_minus(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if ((av[i][0] == '-' || av[i][0] == '+') &&
			(av[i][1] < '0' || av[i][1] > '9' || !av[i][1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac <= i)
		return (0);
	while (i < ac)
	{
		if (!av[i][0])
			return (0);
		if (!(is_number(av[i])))
			return (0);
		i++;
	}
	if (!repeats(ac, av) || !beyond_extremes(ac, av) || !check_minus(ac, av))
		return (0);
	return (1);
}
