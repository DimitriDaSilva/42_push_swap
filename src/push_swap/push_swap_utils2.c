/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:37:39 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/20 14:08:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

/*
** Splits A by pushing values to B that are between the two first breakpoints
** @param:	- [t_list **] a linked list where the stack to sort is stored
**			- [t_list **] an empty linked list that we'll use to sort stack A
**			- [t_list **] partition breakpoints sorted in ascending order
**			- [int] amount of number we have to push to B
** @return:	[int] the number of times we skipped a number that was out of that
**				scope so that we can push to A the sorted numbers that were
**				pushed to A here
** Line-by-line comments:
** @4		See explanation of lines 12 and 15
** @8-9		Looking for numbers within my partition (between 1st and 2nd
**			breakpoints)
** @12-15	To optimize we check if that number is already sorted, if so we
**			don't push to B and we move to the next number
**			We don't count that as ra_count because we otherwise we won't merge
**			the numbers pushed to B before these numbers already sorted
**			Edga case: if it's the first split, we won't be going back to
**			original position before split so we need to push to B all numbers
**			within the partition, regardless of whether they are sorted or not
** @17-18	If value is below first breakpoint, we know that those numbers have
**			been previously sorted so we move on
** @19-23	Account of instructions to look for numbers within partition so that
**			we can retrace our steps like mentionned previously
*/

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
		if ((long)partitions->data <= (long)(*stack_a)->data
			&& (long)(*stack_a)->data < (long)partitions->next->data)
		{
			partition_len--;
			if (is_first_node_a_sorted(*stack_a, *stack_b) && !is_first_split)
				rotate_stack_print(stack_a, "ra");
			else
				push_stack_print(stack_b, stack_a, "pb");
		}
		else if ((long)(*stack_a)->data < (long)partitions->data)
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
** @param:	- [t_list *] a linked list where the stack to sort is stored
**			- [t_list *] stack_b (we need it to merge them into a duplicate to
**						 check as if the stack A would be complete)
** @return:	[int] true or false
** Line-by-line comments:
** @8		Merge stack_a and stack_b into a duplicate
** @13		If they are sorted, last node's final position will be right
**			before the first node
** @14		In case stack_a is small, we need to make sure the size of stack_a
**			is bigger than the last node's final position
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
/*
** Merge B into A while doing an approximate ordering by partitioning the stack
** by using recursion
** @param:	- [t_list **] a linked list where the stack to sort is stored
**			- [t_list *] linked list where are stored values within
*						 current partition
**			- [t_list **] partition breakpoints sorted in ascending order
**			- [int] len that the stack B has at beginning of the function
** Line-by-line comments:
** @5-6		Base case of the recursion: if stack B empty, then return
** @7		Add the median of the current stack B as a new breakpoint partition
** @8-9		During each recursive call, we need to reduce the stack B to half
**			the size it is. Here by half we mean top half. We don't count
**			taking min values as reducing it
** @11-12	If the value is above the median just calculated, we push to A
** 			and we reduce the curr len
** @13-19	If we come accros the smallest value of the stack B, we know it's
**			also the smallest value comparatively to stack A. So we can already
**			sort it by pushing it to A and rotating it (so it goes to bottom)
** @15		We don't reduce the curr_len because it will tamper with the actual
**			numbers we need to push. But we don't need to keep track of how many
**			min values we pushed to send a correct len value to recursive call
** @17		If stack_b is empty, doing ra is a waste because we'll be doing rra
**			right after
** @20-21	Else keep looking on stack B for values to push to A
** @23		RECURSIVE CALL
*/

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

/*
** Rotates the stack A while it's not sorted by checking if the min value is
** closer to top or bottom
** @param:	- [t_list **] linked list with stack A (all numbers at this point)
*/

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
