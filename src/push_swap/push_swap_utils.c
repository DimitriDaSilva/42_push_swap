/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 17:1 b17y dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	split_a_in_two_w_median(t_list **stack_a,
				t_list **stack_b,
				int median,
				int (*cmp)(int, int))
{
	int	half_len;

	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len && !is_sorted(*stack_a))
	{
		if (!cmp(median, (long int)(*stack_a)->data)
			&& !is_first_node_sorted(*stack_a, *stack_b)
			&& half_len--)
			push_stack_print(stack_b, stack_a, "pb");
		else if (is_closer_to_top(*stack_a, median, cmp))
			rotate_stack_print(stack_a, "ra");
		else
			rev_rotate_stack_print(stack_a, "rra");
	}
}

int	is_closer_to_top(t_list *stack, int median, int (*cmp)(int, int))
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

void	merge_b_into_a(t_list **stack_a,
				t_list **stack_b,
				int half_len)
{
	while (*stack_b)
	{
		if ((*stack_b)->next == 0
			&& is_right_position(stack_a, stack_b))
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b)
			&& (*stack_b)->data > (*stack_a)->data)
			rotate_stack_print(stack_a, "ra");
		else if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			push_stack_print(stack_a, stack_b, "pa");
			if (*stack_b != 0)
				rotate_stack_print(stack_a, "ra");
		}
		else if ((long int)(*stack_b)->data == ft_lst_get_max(*stack_b))
			push_stack_print(stack_a, stack_b, "pa");
		else
			rotate_stack_print(stack_b, "rb");
	}
	(void)half_len;
}

int	is_right_position(t_list **stack_a, t_list **stack_b)
{
	int	min_a;
	int	max_a;
	int	check;

	min_a = ft_lst_get_min(*stack_a);
	max_a = ft_lst_get_max(*stack_a);
	if ((long int)(*stack_b)->data < min_a)
		return (min_a == (long int)(*stack_a)->data);
	else if (max_a < (long int)(*stack_b)->data)
		return (min_a == (long int)(*stack_a)->data);
	push_stack(stack_a, stack_b);
	check = is_first_node_sorted(*stack_a, *stack_b);
	push_stack(stack_b, stack_a);
	return (check);
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
		while ((long int)(*stack)->data != min)
			rotate_stack_print(stack, "ra");
	}
	else
	{
		while ((long int)(*stack)->data != min)
			rev_rotate_stack_print(stack, "rra");
	}
}
