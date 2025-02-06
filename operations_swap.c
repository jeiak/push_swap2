/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:55:48 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/27 09:22:51 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*one;
	t_list	*two;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	one = *stack;
	two = one->next;
	one->next = two->next;
	two->next = one;
	*stack = two;
}

void	ft_sa(t_list **stack_a)
{
	ft_swap(stack_a);
	ft_printf("%s \n","sa");
}

void	ft_sb(t_list **stack_b)
{
	ft_swap(stack_b);
	ft_printf("%s \n","sb");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("%s \n","ss");
}
