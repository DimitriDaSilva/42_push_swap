/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:08:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/11 17:58:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_big.h"

void	sort_stack_big(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	min;
	int	median;

	max = ft_lst_find_max(*stack_a);
	min = ft_lst_find_min(*stack_a);
	median = ft_lst_find_median(*stack_a);
	printf("Median: \"%d\"\n", median);
	return ;
	while (!is_sorted(*stack_a))
	{
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
	(void)stack_b;
}
