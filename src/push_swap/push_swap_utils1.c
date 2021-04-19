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

int	get_diff_partitions(t_list *partitions, t_list *stack_a)
{
	t_list	*dup;
	int		index_first;
	int		index_second;
	void	*data_intermediate_node;

	dup = ft_lstdup(stack_a);
	ft_lst_sort(&dup, ascending);
	index_first = ft_lst_get_node_index(dup, (long int)partitions->data);
	index_second = ft_lst_get_node_index(dup, (long int)partitions->next->data);
	if (index_second - index_first > MAX_STACK_INCREMENT
		|| (index_first == 0 && index_second == (ft_lstsize(stack_a) - 1)))
	{
		index_second =  index_first + (index_second - index_first) / 2 + 1;
		data_intermediate_node = ft_lst_get_data_node(dup, index_second);
		ft_lstadd_after_another(partitions, ft_lstnew(data_intermediate_node));
	}
	ft_lstclear(&dup, ft_lstdel_int);
	return (index_second - index_first);
}

int	split_a(t_list **stack_a,
				t_list **stack_b,
				t_list *partitions,
				int partition_len)
{
	int	is_first_split;
	int	ra_count;

	is_first_split = ft_round(ft_lstsize(*stack_a) / 2.0) == partition_len;
	ra_count = 0;
	while (partition_len)
	{
		if ((long int)partitions->data <= (long int)(*stack_a)->data
			&& (long int)(*stack_a)->data < (long int)partitions->next->data)
		{
			partition_len--;
			if (is_first_node_a_sorted(*stack_a, *stack_b) && !is_first_split)
				rotate_stack_print(stack_a, "ra");
			else
				push_stack_print(stack_b, stack_a, "pb");
		}
		else if ((long int)(*stack_a)->data <= (long int)partitions->data)
			rotate_stack_print(stack_a, "ra");
		else
		{
			ra_count++;
			rotate_stack_print(stack_a, "ra");
		}
	}
	return (ra_count);
}

/*
** Checks if the first_node of stack a is sorted in relation to the node
** at the bottom of stack a
** @param:	- [t_list *] stack_a
**			- [t_list *] stack_b (we need it to merge them into a duplicate)
** @return:	[int] true or false
** Line-by-line comments:
** @8		Merge stack_a and stack_b into a duplicate
** @13		If they are sorted, last node's final position will be right
**			before the first node
** @14		In case stack_a is small (below 12), we need to make sure
**			the size of stack_a is bigger than the last node's final position
*/

int	is_first_node_a_sorted(t_list *stack_a, t_list *stack_b)
{
	t_list		*dup;
	int			index_first_node;
	int			index_last_node;
	long long	data_last_node;

	data_last_node = (long long)ft_lst_get_data_last_node(stack_a);
	dup = ft_lstdup(stack_a);
	ft_lstadd_back(&dup, ft_lstdup(stack_b));
	ft_lst_sort(&dup, ascending);
	index_first_node = ft_lst_get_node_index(dup, (long long)stack_a->data);
	index_last_node = ft_lst_get_node_index(dup, data_last_node);
	ft_lstclear(&dup, ft_lstdel_int);
	if (index_last_node == (index_first_node - 1)
		&& ft_lstsize(stack_a) > index_last_node)
		return (1);
	else
		return (0);
}

void	merge_b_into_a_ordering(t_list **stack_a, t_list **stack_b)
{
	int	min_b;
	int	max_b;

	while (*stack_b)
	{
		min_b = ft_lst_get_min(*stack_b);
		max_b = ft_lst_get_max(*stack_b);
		if ((long int)(*stack_a)->data < min_b
			&& is_min_max_closer_to_top(*stack_b, min_b, max_b))
			double_rotate_stack_print(stack_a, stack_b);
		else if ((long int)(*stack_a)->data < min_b)
			rotate_stack_print(stack_a, "ra");
		else if ((long int)(*stack_b)->data == max_b)
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long int)(*stack_b)->data == min_b)
			push_stack_print(stack_a, stack_b, "pa");
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

int	is_min_max_closer_to_top(t_list *stack, int min, int max)
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
