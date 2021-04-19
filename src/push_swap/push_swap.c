/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/19 23:28:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push_swap program outputs the instructions used to sort a list of numbers
** using 2 stacks and a set of predefined instructions
** @param:	- [int] number of args
**			- [char **] param_name + list of numbers
** Line-by-line comments:
** @8		argv + 1 is the address where the list of numbers begins
**			argc - 1 because we need to substract the program_name from the
**			list count
** @11		ft_exit frees the memory allocated and frees the stacks a and b
**			1st arg is the return value. 4th arg is the pointer of instructions
**			which in the case of push_swap doesn't exist
*/

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (1);
	get_stack(argv + 1, argc - 1, &stack_a);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b, 0);
}

/*
** Sorts the stack using different methods depending on the size of the list
** @param:	- [t_list **] a linked list where the list is stored
**			- [t_list **] an emppty linked list that we'll use to sort stack A
** Line-by-line comments:
** @1		Partitions is a linked list with the breakpoints of each partitions.
**			A partition is a segment of the list we need to sort. So the initial
**			partition is the max and min. The partitions need to be in ascending
**			order at all times
*/

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*partitions;
	int		len;

	partitions = 0;
	ft_lstadd_front(&partitions, ft_lstnew((void *)ft_lst_get_max(*stack_a)));
	ft_lstadd_front(&partitions, ft_lstnew((void *)ft_lst_get_min(*stack_a)));
	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	else if (len <= 3)
		sort_stack_small(stack_a);
	else if (len <= 5)
		sort_stack_medium(stack_a, stack_b);
	else
		sort_stack_large(stack_a, stack_b, &partitions);
	ft_lstclear(&partitions, ft_lstdel_int);
}

/*
** Sorts a stack of size 2 or 3
** @param:	- [t_list **] a linked list where the list is stored
** Line-by-line comments:
** @8-11	We know the first item of the stack is already sorted if:
**			- First node is lower than second
**			- OR the first node is the max of the stack and the second
**			is the min
*/

void	sort_stack_small(t_list **stack_a)
{
	int	min;
	int	max;

	min = ft_lst_get_min(*stack_a);
	max = ft_lst_get_max(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if (((long)(*stack_a)->data < (long)(*stack_a)->next->data)
			|| ((long)(*stack_a)->data == max
					&& (long)(*stack_a)->next->data == min))
			rotate_stack_print(stack_a, "ra");
		else
			swap_stack_print(stack_a, "sa");
	}
}

/*
** Sorts a stack of size 4 or 5
** @param:	- [t_list **] a linked list where the list is stored
**			- [t_list **] an emppty linked list that we'll use to sort stack A
** Line-by-line comments:
** @4		We push to stack B the 1 or 2 numbers that are below the median
** @5		We sort the 3 numbers left in A
** @6-8		To reduce instructions, we are checking that stack B is ordered
**			in decreasing order. Otherwise, the merging algo will need
**			2 unnecessary instructions (pa and ra)
*/

void	sort_stack_medium(t_list **stack_a,	t_list **stack_b)
{
	int	median;

	median = ft_lst_get_median(*stack_a);
	split_a_medium(stack_a, stack_b, median);
	sort_stack_small(stack_a);
	if (ft_lstsize(*stack_b) == 2
		&& (long)(*stack_b)->data < (long)(*stack_b)->next->data)
		swap_stack_print(stack_b, "sb");
	merge_b_into_a_ordering(stack_a, stack_b);
}

/*
** For larger stacks (5 and more), we recursively split the stack A in
** more manageable chunks (defined by MAX_STACK_INCREMENT here 20)
** @param:	- [t_list **] a linked list where the list is stored
**			- [t_list **] an emppty linked list that we'll use to sort stack A
**			- [t_list **] partition breakpoints sorted in ascending order
** Line-by-line comments:
** @4-5		Base case of the recursion. Each time we split we create breakpoints
**			and each time we finish to properly sort a partition, we delete its
**			bottom breakpoint, eventually there is nothing more to split and
**			we get to one breakpoint (the maximum value of the stack)
** @6-11	Algo part 1: splitting
** @6		If two first partitions are too far apart, get median between the
**			two breakpoints
** @7		Push to b numbers that are between the 2 first breakpoints. Loop
**			until all expected number found
** @8-11	Come back to initial position by checking the amount of ra
**			instructions executed during the spliting
**			We don't need to go back if it's splited in half (even / odd)
** @12-23	Algo part 2: sorting
** @12-16	If the chunk is manageable, merge while ordering and delete the
**			first breakpoint of the partition
** @19-20	If still not manageable enough, we merge while ordering
**			approximately. While we do it, we create new partitions
** @21		We need to make sure it's sorted. In some cases it won't be
** @22		The first partition from this merger is already sorted so we
**			delete it
** @24		RECURSIVE CALL: we'll split and merge_partitioning while it's not
**			manageable enough
*/

void	sort_stack_large(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions)
{
	int	ra_count;
	int	len_curr_partition;

	if (ft_lstsize(*partitions) == 1)
		return ;
	len_curr_partition = get_diff_partitions(*partitions, *stack_a);
	ra_count = split_a(stack_a, stack_b, *partitions, len_curr_partition);
	if (ft_lstsize(*stack_a) != ft_lstsize(*stack_b)
		&& ft_lstsize(*stack_a) + 1 != ft_lstsize(*stack_b))
		while (ra_count--)
			rev_rotate_stack_print(stack_a, "rra");
	if (ft_lstsize(*stack_b) <= MAX_STACK_INCREMENT)
	{
		merge_b_into_a_ordering(stack_a, stack_b);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	else
	{
		merge_b_into_a_partitioning(stack_a, stack_b, partitions,
									ft_lstsize(*stack_b));
		ft_lst_sort(partitions, ascending);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	sort_stack_large(stack_a, stack_b, partitions);
	rotate_until_sorted(stack_a);
}
