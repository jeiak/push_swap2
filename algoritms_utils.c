/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritms_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:42:07 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/06 13:00:52 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_list *stack)
{
	t_list	*min_node;

	if (!stack)
		return (-1);
	min_node = stack;
	while (stack)
	{
		if (stack->num < min_node->num)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node->index);
}

void move_to_top(t_list **stack, int index)
{
	int pos;
	int size;
	int moves;

	ft_printf("\nDebug - Estado actual de la pila:\n");
	t_list *temp = *stack;
	while (temp)
	{
		ft_printf("Número: %d, Índice: %d\n", temp->num, temp->index);
		temp = temp->next;
	}
	ft_printf("Buscando índice: %d\n", index);
	
	if (!stack || !(*stack))
	return;
	pos = get_position(*stack, index);
	size = ft_lstsize(*stack);
	if (pos == -1)
		return ;
	moves = 0;
	if (pos <= size / 2)
	{
		while ((*stack)->index != index && moves < size)
		{
			ft_ra(stack);
			moves++;
		}
	}
	else
	{
		while ((*stack)->index != index && moves < size)
		{
			ft_rra(stack);
			moves++;
		}
	}
}

int	get_position(t_list *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
/////////////////////////////////////////////////

int	get_target_position(t_list *stack_b, int index)
{
	t_list *current;
	int pos;
	
	pos = 0;
	if (!stack_b)
		return (0);
	current = stack_b;
	while (current)
	{
		if ((current->index < index && (!current->next || 
			current->next->index > index)))
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (pos);
}

int	move_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int cost;

	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		if (pos_a > pos_b)
			cost = pos_a;
		else
			cost = pos_b;
	}
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		if ((size_a - pos_a) > (size_b - pos_b))
			cost = (size_a - pos_a);
		else
			cost = (size_b - pos_b);
	}
	else
	{
		if (pos_a <= size_a / 2)
			cost = pos_a + (size_b - pos_b);
		else
			cost = (size_a - pos_a) + pos_b;
	}
	return (cost);
}

void	calculate_costs(t_list *stack_a, t_list *stack_b)
{
	t_list *current;
	int size_a = ft_lstsize(stack_a);
	int size_b = ft_lstsize(stack_b);
	int pos_a, pos_b, cost;

	current = stack_a;
	while (current)
	{
		pos_a = get_position(stack_a, current->index);
		pos_b = get_target_position(stack_b, current->index);
		cost = move_cost(pos_a, pos_b, size_a, size_b);
		current->cost = cost;
		current = current->next;
	}
}

t_list	*find_optim_move(t_list *stack_a)
{
	t_list	*current;
	t_list	*optim_move;
	int		min_cost;

	min_cost = 2147483647;
	optim_move = NULL;
	current = stack_a;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			optim_move = current;
		}
		current = current->next;
	}
	return (optim_move);
}

void move_optim_b(t_list **stack_a, t_list **stack_b)
{
    t_list *current;
    int best_index = -1;
    int min_cost = 2147483647;
    int size_a = ft_lstsize(*stack_a);
    int size_b = ft_lstsize(*stack_b);

    // Si no hay suficientes elementos para mover
    if (size_a <= 3)
        return;

    // Si stack_b está vacío o tiene solo un elemento, hacer push directo
    if (size_b < 2)
    {
        ft_pb(stack_a, stack_b);
        return;
    }

    // Encontrar el elemento con menor coste
    current = *stack_a;
    while (current)
    {
        int pos_a = get_position(*stack_a, current->index);
        int pos_b = get_target_position(*stack_b, current->index);
        int cost = move_cost(pos_a, pos_b, size_a, size_b);
        
        if (cost < min_cost)
        {
            min_cost = cost;
            best_index = current->index;
        }
        current = current->next;
    }

    if (best_index != -1)
    {
        // Mover el elemento a la cima de stack_a
        int pos_a = get_position(*stack_a, best_index);
        if (pos_a <= size_a / 2)
        {
            for (int i = 0; i < pos_a; i++)
                ft_ra(stack_a);
        }
        else
        {
            for (int i = 0; i < size_a - pos_a; i++)
                ft_rra(stack_a);
        }

        // Hacer el push
        ft_pb(stack_a, stack_b);
    }
}

int validate_indices(t_list *stack)
{
    t_list *current = stack;
    int size = ft_lstsize(stack);
    int *found = calloc(size, sizeof(int));
    int valid = 1;
    
    while (current)
    {
        if (current->index >= 0 && current->index < size)
            found[current->index]++;
        else
        {
            valid = 0;
            break;
        }
        current = current->next;
    }
    
    // Verificar que cada índice aparece exactamente una vez
    for (int i = 0; i < size && valid; i++)
    {
        if (found[i] != 1)
            valid = 0;
    }
    
    free(found);
    return valid;
}

int check_indices(t_list *stack)
{
    t_list *current = stack;
    while (current)
    {
        if (current->index < 0)
            return 0;
        current = current->next;
    }
    return 1;
}