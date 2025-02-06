/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:57:08 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/27 11:20:16 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = NULL;
		last = *stack;
		while (last -> next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("%s \n","rra");
}

void	ft_rrb(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("%s \n","rrb");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("%s \n","rrr");
}
