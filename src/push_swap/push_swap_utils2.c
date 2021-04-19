/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:37:39 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/19 23:27:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	merge_b_into_a_partitioning(t_list **stack_a,
				t_list **stack_b,
				t_list **partitions,
				int old_len)
{
	int	curr_len;
	int	tmp;

	tmp = 0;
	if (old_len == 0 || !(*stack_b))
		return ;
	ft_lstadd_front(partitions, ft_lstnew((void *)ft_lst_get_median(*stack_b)));
	curr_len = old_len;
	while (curr_len > old_len / 2 && *stack_b)
	{
		if ((long)(*partitions)->data <= (long)(*stack_b)->data && curr_len--)
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			tmp++;
			push_stack_print(stack_a, stack_b, "pa");
			if (*stack_b != 0)
				rotate_stack_print(stack_a, "ra");
		}
		else
			rotate_stack_print(stack_b, "rb");
	}
	merge_b_into_a_partitioning(stack_a, stack_b, partitions, curr_len - tmp);
}

void	rotate_until_sorted(t_list **stack)
{
	int	min;
	int	half_len;
	int	index;

	min = ft_lst_get_min(*stack);
	half_len = ft_lstsize(*stack) / 2;
	index = ft_lst_get_node_index(*stack, (long long)min);
	if (index < half_len)
	{
		while ((long)(*stack)->data != min)
			rotate_stack_print(stack, "ra");
	}
	else
	{
		while ((long)(*stack)->data != min)
			rev_rotate_stack_print(stack, "rra");
	}
}

void	split_a_medium(t_list **stack_a,
				t_list **stack_b,
				int median)
{
	int	half_len;

	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len)
	{
		if ((long)(*stack_a)->data < median)
		{
			half_len--;
			push_stack_print(stack_b, stack_a, "pb");
		}
		else if (is_closer_to_top(*stack_a, median))
			rotate_stack_print(stack_a, "ra");
		else
			rev_rotate_stack_print(stack_a, "rra");
	}
}

int	is_closer_to_top(t_list *stack, int median)
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
		if ((long)tmp->data < median)
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
