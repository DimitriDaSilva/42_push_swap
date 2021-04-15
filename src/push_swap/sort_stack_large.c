/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:22:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 12:52:11y dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_large.h"

void	sort_stack_large(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = ft_lst_get_median(*stack_a);
	split_a_in_two_w_median(stack_a, stack_b, median, is_less_than_or_equal);
	merge_b_into_a_w_median(stack_a, stack_b, median / 2, is_less_than);
	// split_a_in_two_w_median(stack_a, stack_b, median, is_greater_than);
	// merge_b_into_a_w_median(stack_a, stack_b, median / 2, is_greater_than);
	rotate_until_sorted(stack_a);
}

static void	merge_b_into_a_w_median(t_list **stack_a,
				t_list **stack_b,
				int first_qrtl,
				int (*cmp)(int, int))
{
	while (*stack_b)
	{
		if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			push_stack_print(stack_a, stack_b, "pa");
			if (*stack_b != 0)
				rotate_stack_print(stack_a, "ra");
		}
		else if (cmp(first_qrtl, (long int)(*stack_b)->data)
			|| ((first_qrtl / 2) <= (long int)(*stack_b)->data && ft_lst_get_max(*stack_b) <= first_qrtl))
			push_stack_print(stack_a, stack_b, "pa");
		else
			rotate_stack_print(stack_b, "rb");
	}
}
