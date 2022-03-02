/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:43:33 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/28 18:23:13 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	rotate(t_stk **stack)
{
	t_stk	*ptr;
	t_stk	*ptr2;
	int		i;

	i = 1;
	if ((*stack)->next == NULL)
		return ;
	ptr = *stack;
	ptr2 = *stack;
	while (ptr2->next)
	{
		ptr2 = ptr2->next;
	}
	*stack = (*stack)->next;
	ptr2->next = ptr;
	ptr->next = NULL;
}

void	rotate_o(t_stk **stacka, t_stk **stackb, int opt)
{
	if (opt == 1)
	{
		rotate(stacka);
	}
	if (opt == 2)
	{
		rotate(stackb);
	}
	if (opt == 3)
	{
		rotate(stacka);
		rotate(stackb);
	}
}
