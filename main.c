/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:41:03 by jesssanc          #+#    #+#             */
/*   Updated: 2025/01/21 12:55:45 by jesssanc         ###   ########.fr       */
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

void	ft_fill(t_list **stack, char **numbers)
{
	t_list	*new;
	int		i;

	i = 0;
	while (numbers[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(numbers[i]));
		if (!new)
			return ;
		ft_lstadd_back(stack, new);
		i++;
	}
}

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers && numbers[i])
		free(numbers[i++]);
	free(numbers);
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
		if (!numbers || !is_valid_nbr(numbers))
			return (free_numbers(numbers), NULL);
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
			ft_fill(&stack, &argv[i]);
			i++;
		}
	}
	return (stack);
}

int	main(int argc, char **argv )
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = get_numbers(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	// implementar el algoritmo
	return (0);
}
