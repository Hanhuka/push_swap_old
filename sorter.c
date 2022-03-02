/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:26:50 by ralves-g          #+#    #+#             */
/*   Updated: 2022/03/02 11:15:58 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	sort_100(t_stk **stacka, t_stk **stackb)
{
	treat_chunks2(stacka, stackb, 6);
	while (stack_size(*stacka) > 3)
	{
		if ((*stacka)->value < 0)
		{
			push_o(stacka, stackb, 2);
			rotate_o(stacka, stackb, 2);
		}
		else if ((*stacka)->value >= find_third(*stacka))
			rotate_o(stacka, stackb, 1);
		else
			push_o(stacka, stackb, 2);
	}
	while (stack_size(*stacka) < 3)
		push_o(stacka, stackb, 1);
	size_3(stacka, stackb);
	while (stack_size(*stackb) > 0)
		treat_plus(stacka, stackb);
	if (!is_ordered(*stacka))
		put_back(stacka, stackb, 2);
}

void	sort_500(t_stk **stacka, t_stk **stackb)
{
	treat_chunks2(stacka, stackb, 15);
	while (stack_size(*stacka) > 3)
	{
		if ((*stacka)->value < 0)
		{
			push_o(stacka, stackb, 2);
			rotate_o(stacka, stackb, 2);
		}
		else if ((*stacka)->value >= find_third(*stacka))
			rotate_o(stacka, stackb, 1);
		else
			push_o(stacka, stackb, 2);
	}
	while (stack_size(*stacka) < 3)
		push_o(stacka, stackb, 1);
	size_3(stacka, stackb);
	while (stack_size(*stackb) > 0)
		treat_plus(stacka, stackb);
	if (!is_ordered(*stacka))
		put_back(stacka, stackb, 2);
}

void	less_100(t_stk **stacka, t_stk **stackb)
{
	int	i;
	int	size;

	size = stack_size(*stacka);
	i = size - 3;
	if (is_ordered(*stacka))
		return ;
	while (i > 0)
	{
		push_o(stacka, stackb, 2);
		i--;
	}
	size_3 (stacka, stackb);
	i = size - 3;
	while (i > 0)
	{
		put_back(stacka, stackb, 1);
		i--;
	}
	if (!is_ordered(*stacka))
		put_back(stacka, stackb, 2);
}

void	sorter(t_stk **stacka, t_stk **stackb)
{
	if (stack_size(*stacka) == 2)
	{
		if ((*stacka)->value > (*stacka)->next->value)
			swap_o(stacka, stackb, 1);
	}
	else if (stack_size(*stacka) < 100)
		less_100(stacka, stackb);
	else if (stack_size(*stacka) == 100)
		sort_100(stacka, stackb);
	else if (stack_size(*stacka) > 100)
		sort_500(stacka, stackb);
}
