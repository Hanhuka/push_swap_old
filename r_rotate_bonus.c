/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:46 by ralves-g          #+#    #+#             */
/*   Updated: 2022/02/28 18:22:42 by ralves-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

void	r_rotate(t_stk **stack)
{
	t_stk	*ptr;
	t_stk	*ptr2;
	int		i;

	i = 1;
	if ((*stack)->next == NULL)
		return ;
	i = 1;
	ptr2 = *stack;
	while (i < stack_size(*stack) - 1)
	{
		ptr2 = ptr2->next;
		i++;
	}
	ptr = ptr2->next;
	ptr2->next = NULL;
	ptr->next = *stack;
	*stack = ptr;
}

void	r_rotate_o(t_stk **stacka, t_stk **stackb, int opt)
{
	if (opt == 1)
	{
		r_rotate(stacka);
	}
	if (opt == 2)
	{
		r_rotate(stackb);
	}
	if (opt == 3)
	{
		r_rotate(stacka);
		r_rotate(stackb);
	}
}
