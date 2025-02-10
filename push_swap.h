/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:57:41 by jesssanc          #+#    #+#             */
/*   Updated: 2025/02/10 12:48:00 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

/*typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_slist;*/
void	ft_swap(t_list **stack);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **dest, t_list **src);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_b, t_list **stack_a);
void	ft_rotate(t_list **stack);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
t_list	*get_numbers(int argc, char **argv);
int		is_valid_nbr(const char *str);
int		is_duplicate(t_list *stack);
void	ft_fill(t_list **stack, char **numbers);
void	free_numbers(char **numbers);
void	get_index(t_list *stack);
void	sort_three_num(t_list **stack_a);
void	big_sort(t_list **stack_a, t_list **stack_b);
//void	sort_four_five(t_list **stack_a, t_list **stack_b);
int		find_min_index(t_list *stack);
void	move_to_top(t_list **stack, int index);
int		get_position(t_list *stack, int index);
int		get_target_position(t_list *stack_b, int index);
int		move_cost(int pos_a, int pos_b, int size_a, int size_b);
void	calculate_costs(t_list *stack_a, t_list *stack_b);
t_list	*find_optim_move(t_list *stack_a);
void	move_optim_b(t_list **stack_a, t_list **stack_b);
int		validate_indices(t_list *stack);
int		check_indices(t_list *stack);
void	print_stack(t_list *stack);
void	sort_two_num(t_list **stack_a);

#endif
