/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:44:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 08:46:13 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_small.h"

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
