/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:21:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/11 10:11:57 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	if (len <= 4)
		sort_stack_small(stack_a);
	(void)stack_b;
}

void	sort_stack_small(t_list **stack_a)
{
	int	max;
	int	min;

	max = ft_lst_find_max(*stack_a);
	min = ft_lst_find_min(*stack_a);
	while (!is_sorted(*stack_a))
	{
		// ft_lst_print_d(*stack_a);
		// sleep(2);
		if ((*stack_a)->data < (*stack_a)->next->data
			|| ((long int)(*stack_a)->data == max
			&& (long int)(*stack_a)->next->data == min))
		{
			printf("ra\n");
			rotate_stack(stack_a);
		}
		else
		{
			printf("sa\n");
			swap_stack(stack_a);
		}
	}
}
