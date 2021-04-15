/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:48:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 08:59:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_medium.h"

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
