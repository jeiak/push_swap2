/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:41:03 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:04 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*quitar la función print stack*/
void	print_stack(t_list *stack)
{
	t_list	*current = stack;

	while (current != NULL)
	{
		ft_printf("num:%d, index:%d \n", current->num, current->index);
		current = current->next;
	}
	printf("\n");
}

void	ft_fill(t_list **stack, char **numbers)
{
	t_list	*new;
	int		i;

	i = 0;
	if (numbers[1] == NULL)
	{
		new = ft_lstnew(ft_atoi(numbers[0]));
		if (!new)
			return ;
		ft_lstadd_back(stack, new);
		return ;
	}
	while (numbers[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(numbers[i]));
		if (!new)
			return ;
		ft_lstadd_back(stack, new);
		i++;
	}
}



int	main(int argc, char **argv )
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = get_numbers(argc, argv);
	if (!stack_a || is_duplicate(stack_a))
	{
		ft_printf("Error: Duplicates found or invalid input\n");
		return (1);
	}
	stack_b = NULL;
	get_index(stack_a);
	if (!check_indices(stack_a))
	{
		ft_printf("Error: Invalid indices\n");
		return (1);
	}
	ft_printf("Stack inicial:\n");
	print_stack(stack_a);
	big_sort(&stack_a, &stack_b);
	ft_printf("Stack final:\n");
	print_stack(stack_a);
	return (0);
}
