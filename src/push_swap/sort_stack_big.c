/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:49:14 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 08:50:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_big.h"

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
