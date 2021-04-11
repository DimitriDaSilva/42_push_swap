/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:08:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/11 22:29:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_big.h"

void	sort_stack_big(t_list **stack_a, t_list **stack_b, int len)
{
	int	max;
	int	min;
	int	median;

	max = ft_lst_find_max(*stack_a);
	min = ft_lst_find_min(*stack_a);
	median = ft_lst_find_median(*stack_a);
	split_in_two_w_median(stack_a, stack_b, median, len / 2);
	merge_b_into_a(stack_a, stack_b, median, len / 2);
	return ;
	(void)min;
	(void)max;
}

static void	split_in_two_w_median(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int half_len)
{
	while (half_len)
	{
		if (median <= (long int)(*stack_a)->data)
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

	while (half_len)
	{
		min_b = ft_lst_find_min(*stack_b);
		if ((long int)(*stack_b)->data == min_b)
		{
			printf("pa\n");
			push_stack(stack_a, stack_b);
			half_len--;
			printf("ra\n");
			rotate_stack(stack_a);
		}
		else
		{
			printf("rb\n");
			rotate_stack(stack_b);
		}
	}
	(void)median;
}