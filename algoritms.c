/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:09:21 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/08 18:23:48 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_num(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
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
/*
void	sort_four_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min_index = find_min_index(*stack_a);
		move_to_top(stack_a, min_index);
		ft_pb(stack_b, stack_a);
		size--;
	}
	sort_three_num(stack_a);
	if ((*stack_b)->index < (*stack_a)->index)
		ft_pa(stack_a, stack_b);
	else
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
	if ((*stack_b) && (*stack_b)->index < (*stack_a)->index)
		ft_pa(stack_a, stack_b);
	else if (*stack_b)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}
*/

void big_sort(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);

    // Si hay 3 o menos números, usar sort_three_num
    if (size <= 3)
    {
        sort_three_num(stack_a);
        return;
    }

    // Mover todos excepto 3 números a B
    while (ft_lstsize(*stack_a) > 3)
    {
        // Encontrar el menor número y moverlo a B
        int min_pos = 0;
        t_list *current = *stack_a;
        t_list *min_node = current;
        int pos = 0;

        // Encontrar el número más pequeño
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

        // Mover el número más pequeño a la cima
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

        // Push a B
        ft_pb(stack_a, stack_b);
    }

    // Ordenar los 3 números que quedan en A
    sort_three_num(stack_a);

    // Devolver todos los números de B a A
    while (*stack_b)
        ft_pa(stack_a, stack_b);
}