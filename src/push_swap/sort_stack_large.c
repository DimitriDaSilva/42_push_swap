/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:22:23 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 12:52:11y dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack_large.h"

void	sort_stack_large(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	first_qrtl;

	median = ft_lst_get_median(*stack_a);
	first_qrtl = ft_lst_get_qrtl(*stack_a, 1);
	split_a_in_two_w_median(stack_a, stack_b, median, is_less_than_or_equal);
	merge_b_into_a_w_median(stack_a, stack_b, first_qrtl, is_less_than);
	while (is_first_node_a_sorted(*stack_a))
		rotate_stack_print(stack_a, "ra");
	while ((long int)(*stack_a)->data < first_qrtl)
		push_stack_print(stack_b, stack_a, "pb");
	merge_b_into_a_in_order(stack_a, stack_b);
	rotate_until_sorted(stack_a);
}

static void	merge_b_into_a_in_order(t_list **stack_a, t_list **stack_b)
{
	int	min_b;
	int	max_b;

	min_b = ft_lst_get_min(*stack_b);
	max_b = ft_lst_get_max(*stack_b);
	while (*stack_b)
	{
		if ((long int)(*stack_b)->data == ft_lst_get_max(*stack_b))
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			push_stack_print(stack_a, stack_b, "pa");
			rotate_stack_print(stack_a, "ra");
		}
		else if (is_min_max_closer_to_top(*stack_b, min_b, max_b))
			rotate_stack_print(stack_b, "rb");
		else
			rev_rotate_stack_print(stack_b, "rrb");
	}
}

/*
** Check if min or max of stack_b is closer to top than it is from bottom
** @param:	- [t_list *] stack b
**			- [int] min of stack b
** @return:	[int] true or false
** Line-by-line comments:
** @9-10	If index min is closer to top than max then to know if either
*/

static int	is_min_max_closer_to_top(t_list *stack, int min, int max)
{
	int		len;
	int		index_min;
	int		index_max;
	int		check;

	len = ft_lstsize(stack);
	index_min = ft_lst_get_node_index(stack, min);
	index_max = ft_lst_get_node_index(stack, max);
	if (index_min < index_max)
		check = (index_min < (len - index_max));
	else
		check = (index_max < (len - index_min));
	return (check);
}

static void	merge_b_into_a_w_median(t_list **stack_a,
				t_list **stack_b,
				int first_qrtl,
				int (*cmp)(int, int))
{
	while (*stack_b)
	{
		if ((long int)(*stack_b)->data == ft_lst_get_min(*stack_b))
		{
			push_stack_print(stack_a, stack_b, "pa");
			if (*stack_b != 0)
				rotate_stack_print(stack_a, "ra");
		}
		else if (cmp(first_qrtl, (long int)(*stack_b)->data)
			|| ((first_qrtl / 2) <= (long int)(*stack_b)->data
					&& ft_lst_get_max(*stack_b) <= first_qrtl))
			push_stack_print(stack_a, stack_b, "pa");
		else
			rotate_stack_print(stack_b, "rb");
	}
}

static int	is_first_node_a_sorted(t_list *stack_a)
{
	t_list	*dup;
	int		index_first_node;
	int		index_last_node;
	void	*data_last_node;

	data_last_node = ft_lst_get_data_last_node(stack_a);
	dup = ft_lstdup(stack_a);
	ft_lst_sort(&dup, ascending);
	index_first_node = ft_lst_get_node_index(dup, (long long)stack_a->data);
	index_last_node = ft_lst_get_node_index(dup, (long long)data_last_node);
	ft_lstclear(&dup, ft_lstdel_int);
	if (index_last_node == (index_first_node - 1))
		return (1);
	else
		return (0);
}
