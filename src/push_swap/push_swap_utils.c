/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 10:22:26 by dda-silv         ###   ########.fr       */
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
			printf("ra\n");
			rotate_stack(stack_a);
		}
		else
		{
			printf("pb\n");
			push_stack(stack_b, stack_a);
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
		if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			printf("pa\n");
			push_stack(stack_a, stack_b);
			printf("ra\n");
			rotate_stack(stack_a);
		}
		else if ((long int)(*stack_b)->data == ft_lst_get_max(*stack_b))
		{
			printf("pa\n");
			push_stack(stack_a, stack_b);
		}
		else
		{
			printf("rb\n");
			rotate_stack(stack_b);
		}
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
		{
			printf("ra\n");
			rotate_stack(stack);
		}
	}
	else
	{
		while ((long int)(*stack)->data != min)
		{
			printf("rra\n");
			rev_rotate_stack(stack);
		}
	}
}
