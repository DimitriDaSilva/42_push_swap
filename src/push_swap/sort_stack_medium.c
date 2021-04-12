/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:08:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/12 15:01:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_medium.h"

void	sort_stack_medium(t_list **stack_a, t_list **stack_b, int len)
{
	int	max;
	int	min;
	int	median;

	max = ft_lst_get_max(*stack_a);
	min = ft_lst_get_min(*stack_a);
	median = ft_lst_get_median(*stack_a);
	split_a_in_two_w_median(stack_a, stack_b, median, is_less_than_or_equal);
	merge_b_into_a(stack_a, stack_b, median, len / 2);
	split_a_in_two_w_median(stack_a, stack_b, median, is_greater_than);
	merge_b_into_a(stack_a, stack_b, median, len / 2);
	rotate_until_sorted(stack_a);
	return ;
	(void)min;
	(void)max;
}

static void	split_a_in_two_w_median(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int (*cmp)(int, int))
{
	int	half_len;

	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len)
	{
		if (cmp(median, (long int)(*stack_a)->data))
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

static void	merge_b_into_a(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int half_len)
{
	int	min_b;
	int	max_b;

	while (half_len)
	{
		min_b = ft_lst_get_min(*stack_b);
		max_b = ft_lst_get_max(*stack_b);
		if ((long int)(*stack_b)->data == min_b)
		{
			printf("pa\n");
			push_stack(stack_a, stack_b);
			half_len--;
			printf("ra\n");
			rotate_stack(stack_a);
		}
		else if ((long int)(*stack_b)->data == max_b)
		{
			printf("pa\n");
			push_stack(stack_a, stack_b);
			half_len--;
		}
		else
		{
			printf("rb\n");
			rotate_stack(stack_b);
		}
	}
	(void)median;
}

static void	rotate_until_sorted(t_list **stack)
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
