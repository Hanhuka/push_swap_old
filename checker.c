/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:24:48 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/02 11:13:31 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include <stdio.h>

void	ft_lstclear(t_stk **stack)
{
	t_stk	*ptr;

	if (!stack || !*stack)
		return ;
	while (stack && *stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

void	create_stack(t_stk **stacka, t_stk **stackb, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		stackadd_back(stacka, new_module(ft_atoi(av[i])));
		i++;
	}
	stackb = NULL;
}

void	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			write(1, "ERROR\n", 6);
			exit(0);
		}
		i++;
	}
}

void	treat_input(t_stk **stacka, t_stk **stackb)
{
	char	*str;

	str = get_next_line(0);
	if (str)
		treat_comm(str, stacka, stackb);
	check_spaces(str);
	while (str != NULL)
	{
		str = get_next_line(0);
		if (str)
		{
			treat_comm(str, stacka, stackb);
			free(str);
		}
	}
}

int	main(int ac, char **av)
{
	t_stk	*stacka;
	t_stk	*stackb;
	int		i;

	stacka = NULL;
	i = 1;
	if (ac == 1)
		return (1);
	if (!checker(ac, av))
	{
		write(1, "ERROR\n", 6);
		return (-1);
	}
	create_stack(&stacka, &stackb, ac, av);
	treat_input(&stacka, &stackb);
	if (is_ordered(stacka) && stack_size(stackb) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stacka);
}
