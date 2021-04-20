/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:19:32 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/20 14:07:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

/*
** Simplified version of split_a(). Main difference is that it's optimized to
** look for the most appropriate value to push to B and alternates ra or rra
** depending on is_closer_to_top's result
** @param:	- [t_list **] a linked list where the stack to sort is stored
**			- [t_list **] an empty linked list that we'll use to sort stack A
*/

void	split_a_medium(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	half_len;

	median = ft_lst_get_median(*stack_a);
	half_len = ft_lstsize(*stack_a) / 2;
	while (half_len)
	{
		if ((long)(*stack_a)->data < median)
		{
			half_len--;
			push_stack_print(stack_b, stack_a, "pb");
		}
		else if (is_median_closer_to_top(*stack_a, median))
			rotate_stack_print(stack_a, "ra");
		else
			rev_rotate_stack_print(stack_a, "rra");
	}
}

/*
** Checks if a value bellow the median is closer to top than it is from bottom
** @param:	- [t_list *] a linked list where the stack to sort is stored
**			- [int] median
** @return:	[int] true or false
** Line-by-line comments:
** @9-20	Parsing looking for values below median
** @13-14	We already previously set the value of first_index then it no
**			longer will be -1
** @21-22	If last_index is -1 it means that he only found one median so
**			we just need to check if the median found is on the first half of
**			the stack
*/

int	is_median_closer_to_top(t_list *stack, int median)
{
	int		check;
	int		curr_index;
	int		first_index;
	int		last_index;

	curr_index = 0;
	first_index = -1;
	last_index = -1;
	while (stack)
	{
		if ((long)stack->data < median)
		{
			if (first_index == -1)
				first_index = curr_index;
			else
				last_index = curr_index;
		}
		curr_index++;
		stack = stack->next;
	}
	if (last_index == -1)
		check = first_index < (curr_index / 2);
	else
		check = first_index < (curr_index - last_index);
	return (check);
}

/*
** Merge stack B into A while ordering the values
** @param:	- [t_list *] a linked list where the stack to sort is stored
**			- [t_list *] linked list where are stored values within
*						 current partition
** Line-by-line comments:
** @8-10	We know that if both conditions in lines 11-12 and 17-18 are true
**			we end up doing ra and rb consecutively, so we optimize with "rr"
** @11-12	If the smaller number of stack B is smaller than the top of stack A,
**			we need to move on to the next number. At this point in the algo,
**			all numbers before that in stack A are already sorted
** @13-16	The goal of the algo is to find the min and max of the stack B and
**			push them to A
** @17-20	Optimization: checking if min or max is closer to top or bottom of
**			the stack
*/

void	merge_b_into_a_ordering(t_list **stack_a, t_list **stack_b)
{
	int	min_b;
	int	max_b;

	while (*stack_b)
	{
		min_b = ft_lst_get_min(*stack_b);
		max_b = ft_lst_get_max(*stack_b);
		if ((long)(*stack_a)->data < min_b
			&& is_min_max_closer_to_top(*stack_b, min_b, max_b))
			double_rotate_stack_print(stack_a, stack_b);
		else if ((long)(*stack_a)->data < min_b)
			rotate_stack_print(stack_a, "ra");
		else if ((long)(*stack_b)->data == max_b)
			push_stack_print(stack_a, stack_b, "pa");
		else if ((long)(*stack_b)->data == min_b)
			push_stack_print(stack_a, stack_b, "pa");
		else if (is_min_max_closer_to_top(*stack_b, min_b, max_b))
			rotate_stack_print(stack_b, "rb");
		else
			rev_rotate_stack_print(stack_b, "rrb");
	}
}

/*
** Checks if min or max of stack is closer to top than it is from bottom
** Function used by both stack A and stack B throughout algo
** @param:	- [t_list *] a linked list where the stack to sort is stored
**			- [int] min of stack
**			- [int] max of stack
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
/*
** Gets the difference between two breakpoint partitions. If the difference
** is higher than 20 (i.e. MAX_STACK_INCREMENT), creates an intermediate
** partition that is half the size of the one found
** @param:	- [t_list **] partition breakpoints sorted in ascending order
** 			- [t_list **] a linked list where the list is stored
** @return:	[int] size of the current partitions
** Line-by-line comments:
** @8-9		Finds the indexes of the first and second breakpoints in a sorted
**			stack 
** @10-16	Split current partitions in half if:
**			- Its size is superior to MAX_INCREMENT_STACK
**			- OR first split (min and max are the breakpoints)
** @13-15	The number breakpoint is set after the first one
*/

int	get_diff_partitions(t_list *partitions, t_list *stack_a)
{
	t_list	*dup;
	int		index_first;
	int		index_second;
	void	*data_intermediate_node;

	dup = ft_lstdup(stack_a);
	ft_lst_sort(&dup, ascending);
	index_first = ft_lst_get_node_index(dup, (long)partitions->data);
	index_second = ft_lst_get_node_index(dup, (long)partitions->next->data);
	if (index_second - index_first > MAX_STACK_INCREMENT
		|| (index_first == 0 && index_second == (ft_lstsize(stack_a) - 1)))
	{
		index_second = index_first + (index_second - index_first) / 2 + 1;
		data_intermediate_node = ft_lst_get_data_node(dup, index_second);
		ft_lstadd_after_another(partitions, ft_lstnew(data_intermediate_node));
	}
	ft_lstclear(&dup, ft_lstdel_int);
	return (index_second - index_first);
}
