/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:09:21 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/10 12:37:07 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two_num(t_list **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return;
	if ((*stack_a)->index > (*stack_a)->next->index)
		ft_sa(stack_a);
}

void	sort_three_num(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second > third)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (first > third && third > second)
		ft_ra(stack_a);
	else if (second > third && third > first)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (second > first && first > third)
		ft_sa(stack_a);
	else if (first > second && third > first)
		ft_rra(stack_a);
}


void big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*min_node;

	if (ft_lstsize(*stack_a) <= 3)
	{
		sort_three_num(stack_a);
		return;
	}
	while (ft_lstsize(*stack_a) >= 3)
	{
		int min_pos = 0;
		current = *stack_a;
		min_node = current;
 		int pos = 0;
		while (current)
		{
			if (current->index < min_node->index)
			{
				min_node = current;
				min_pos = pos;
			}
			current = current->next;
			pos++;
		}
		if (min_pos <= ft_lstsize(*stack_a) / 2)
		{
			while (min_pos-- > 0)
				ft_ra(stack_a);
		}
		else
		{
			while (min_pos++ < ft_lstsize(*stack_a))
				ft_rra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three_num(stack_a);
	else if (ft_lstsize(*stack_a) == 2)
		sort_two_num(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}
