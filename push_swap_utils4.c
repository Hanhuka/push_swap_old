/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 03:55:55 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/10 04:51:11 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_lower(t_stk *stack, int value)
{
	int		low;
	int		i;
	t_stk	*ptr;

	ptr = 0;
	low = 0;
	i = 0;
	ptr = stack;
	while (i < stack_size(stack) && ptr->value > value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == stack_size(stack))
		low = 1;
	return (low);
}

int	is_bigger(t_stk *stack, int value)
{
	int		big;
	int		i;
	t_stk	*ptr;

	ptr = 0;
	big = 0;
	i = 0;
	ptr = stack;
	while (i < stack_size(stack) && ptr->value < value)
	{
		ptr = ptr->next;
		i++;
	}
	if (i == stack_size(stack))
		big = 1;
	return (big);
}

int	find_smallest(t_stk *stack)
{
	int		pos;
	int		val;
	int		i;
	t_stk	*ptr;

	val = stack->value;
	pos = 1;
	i = 1;
	ptr = stack;
	while (i <= stack_size(stack))
	{
		if (ptr->value < val)
		{
			val = ptr->value;
			pos = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (pos);
}

int	get_smallest(t_stk *stack)
{
	int		pos;
	int		val;
	int		i;
	t_stk	*ptr;

	val = stack->value;
	pos = 1;
	i = 1;
	ptr = stack;
	while (i <= stack_size(stack))
	{
		if (ptr->value < val)
		{
			val = ptr->value;
			pos = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (val);
}

void	put_order(t_stk **stacka, t_stk **stackb)
{
	int	moves;
	int	opt;

	opt = 0;
	if (find_smallest(*stacka)
		> stack_size(*stacka) / 2 + stack_size(*stacka) % 2)
	{
		moves = stack_size(*stacka) - find_smallest(*stacka) + 1;
		opt = 1;
	}
	else
		moves = find_smallest(*stacka) - 1;
	move(stacka, stackb, moves, opt);
}
