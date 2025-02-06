/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:56:50 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/27 11:19:30 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		*stack = first->next;
		first->next = NULL;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
	}
}

void	ft_ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("%s \n","ra");
}

void	ft_rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("%s \n","rb");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("%s \n","rr");
}
