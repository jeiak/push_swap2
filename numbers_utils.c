/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:14:03 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:49 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_nbr(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_list *stack)
{
	t_list	*current;
	t_list	*compare;

	current = stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->num == compare->num)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

t_list	*get_numbers(int argc, char **argv)
{
	t_list	*stack;
	char	**numbers;
	int		i;

	stack = NULL;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers || !is_valid_nbr(*numbers))
			return (free_numbers(numbers), NULL); // meter Error?
		ft_fill(&stack, numbers);
		free_numbers(numbers);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!is_valid_nbr(argv[i]))
				return (NULL); // meter Error?
			ft_fill(&stack, (char *[2]){argv[i], NULL});
			i++;
		}
	}
	return (stack);
}
void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers && numbers[i])
		free(numbers[i++]);
	free(numbers);
}

