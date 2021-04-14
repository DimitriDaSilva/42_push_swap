/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:21:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 17:54:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	else if (len <= 3)
		sort_stack_small(stack_a);
	else if (len <= 5)
		sort_stack_medium(stack_a, stack_b);
	else
		sort_stack_big(stack_a, stack_b, len);
}

void	sort_stack_small(t_list **stack_a)
{
	int	max;
	int	min;

	max = ft_lst_get_max(*stack_a);
	min = ft_lst_get_min(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->data < (*stack_a)->next->data
			|| ((long int)(*stack_a)->data == max
						&& (long int)(*stack_a)->next->data == min))
			rotate_stack_print(stack_a, "ra");
		else
			swap_stack_print(stack_a, "sa");
	}
}

void	sort_stack_medium(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	len;

	median = ft_lst_get_median(*stack_a);
	len = ft_lstsize(*stack_a);
	split_a_in_two_w_median(stack_a, stack_b, median, is_less_than_or_equal);
	sort_stack_small(stack_a);
	if (ft_lstsize(*stack_b) == 2 && (*stack_b)->data < (*stack_b)->next->data)
		swap_stack_print(stack_b, "sb");
	merge_b_into_a(stack_a, stack_b, len / 2);
	rotate_until_sorted(stack_a);
}

void	sort_stack_big(t_list **stack_a, t_list **stack_b, int len)
{
	int	median;

	median = ft_lst_get_median(*stack_a);
	split_a_in_two_w_median(stack_a, stack_b, median, is_less_than_or_equal);
	merge_b_into_a(stack_a, stack_b, len / 2);
	split_a_in_two_w_median(stack_a, stack_b, median, is_greater_than);
	merge_b_into_a(stack_a, stack_b, len / 2);
	rotate_until_sorted(stack_a);
}
