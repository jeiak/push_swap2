/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:56:32 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/30 12:58:04 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("%s \n","pa");
}

void	ft_pb(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("%s \n","pb");
}
