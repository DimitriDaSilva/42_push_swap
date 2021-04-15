/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:48:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 10:41:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_medium.h"

void	sort_stack_medium(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	len;

	median = ft_lst_get_median(*stack_a);
	len = ft_lstsize(*stack_a);
	split_a_in_two_medium(stack_a, stack_b, median, is_less_than_or_equal);
	sort_stack_small(stack_a);
	if (ft_lstsize(*stack_b) == 2 && (*stack_b)->data < (*stack_b)->next->data)
		swap_stack_print(stack_b, "sb");
	merge_b_into_a(stack_a, stack_b, len / 2);
	rotate_until_sorted(stack_a);
}

static void	split_a_in_two_medium(t_list **stack_a,
				t_list **stack_b,
				int median,
				int (*cmp)(int, int))
{
	int	half_len;

	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len)
	{
		if (!cmp(median, (long int)(*stack_a)->data))
		{
			half_len--;
			push_stack_print(stack_b, stack_a, "pb");
		}
		else if (is_closer_to_top(*stack_a, median, cmp))
			rotate_stack_print(stack_a, "ra");
		else
			rev_rotate_stack_print(stack_a, "rra");
	}
}

static int	is_closer_to_top(t_list *stack, int median, int (*cmp)(int, int))
{
	t_list	*tmp;
	int		curr_index;
	int		first_index;
	int		last_index;

	tmp = stack;
	curr_index = 0;
	first_index = -1;
	last_index = -1;
	while (tmp)
	{
		if (!cmp(median, (long int)tmp->data))
		{
			if (first_index == -1)
				first_index = curr_index;
			else
				last_index = curr_index;
		}
		curr_index++;
		tmp = tmp->next;
	}
	if (last_index == -1)
		return (first_index < curr_index / 2);
	else
		return (first_index < (curr_index - last_index));
}
