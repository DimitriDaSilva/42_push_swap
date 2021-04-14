/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 16:47:22 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	split_a_in_two_w_median(t_list **stack_a,
				t_list **stack_b,
				int median,
				int (*cmp)(int, int))
{
	int	half_len;

	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len && !is_sorted(*stack_a))
	{
		if (cmp(median, (long int)(*stack_a)->data)
			|| is_first_node_sorted(*stack_a, *stack_b))
		{
			
			rotate_stack_print(stack_a, "ra");
		}
		else
		{
			push_stack_print(stack_b, stack_a, "pb");
			half_len--;
		}
	}
}

void	merge_b_into_a(t_list **stack_a,
				t_list **stack_b,
				int half_len)
{
	while (*stack_b)
	{
		if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b)
				&& (*stack_b)->data > (*stack_a)->data)
			rotate_stack_print(stack_a, "ra");
		else if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			push_stack_print(stack_a, stack_b, "pa");
			rotate_stack_print(stack_a, "ra");
		}
		else if ((long int)(*stack_b)->data == ft_lst_get_max(*stack_b))
			push_stack_print(stack_a, stack_b, "pa");
		else
			rotate_stack_print(stack_b, "rb");
	}
	(void)half_len;
}

void	rotate_until_sorted(t_list **stack)
{
	int	min;
	int	half_len;
	int	index;

	min = ft_lst_get_min(*stack);
	half_len = ft_lstsize(*stack) / 2;
	index = ft_lst_get_node_index(*stack, (long long)min);
	if (index < half_len)
	{
		while ((long int)(*stack)->data != min)
			rotate_stack_print(stack, "ra");
	}
	else
	{
		while ((long int)(*stack)->data != min)
			rev_rotate_stack_print(stack, "rra");
	}
}
