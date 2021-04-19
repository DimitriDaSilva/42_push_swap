/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/19 19:25:34 by dda-silv         ###   ########.fr       */
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
** @2		Partitions is a linked list with the breakpoints of each partitions.
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
		sort_stack_medium(stack_a, stack_b, &partitions);
	else
		sort_stack_large(stack_a, stack_b, &partitions);
}

/*
** Sorts a stack of size 3 or less
** @param:	- [t_list **] a linked list where the list is stored
**			- [type] param_value
** @return:	[type] return_value
** Line-by-line comments:
** @line-line	comment
*/

void	sort_stack_small(t_list **stack_a)
{
	int	min;
	int	max;

	min = ft_lst_get_min(*stack_a);
	max = ft_lst_get_max(*stack_a);
	while (!is_sorted(*stack_a))
	{
		if (((long int)(*stack_a)->data < (long int)(*stack_a)->next->data)
			|| ((long int)(*stack_a)->data == max
						&& (long int)(*stack_a)->next->data == min))
			rotate_stack_print(stack_a, "ra");
		else
			swap_stack_print(stack_a, "sa");
	}
}

void	sort_stack_medium(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions)
{
	int	median;

	median = ft_lst_get_median(*stack_a);
	split_a_medium(stack_a, stack_b, median);
	sort_stack_small(stack_a);
	if (ft_lstsize(*stack_b) == 2 && (*stack_b)->data < (*stack_b)->next->data)
		swap_stack_print(stack_b, "sb");
	merge_b_into_a_ordering(stack_a, stack_b);
	rotate_until_sorted(stack_a);
	(void)partitions;
}

/*
** For larger stacks (5 and more), the logics works as follows:
** 1. Split stack A in 2 - above median in A & below median in B
** 2. Merge stack B into A
**    - First push to A values above 1st quartile and min values
**    - Second, push to A values below 1st quartile
** 3. In a loop, by increments of 12, parse the stack A and sort it using
**    the stack B
** @param:	- [t_list **] head of the list stack_a
**			- [t_list **] head of the list stack_b
** Line-by-line comments:
** @line-line	comment
*/

void	sort_stack_large(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions)
{
	int	ra_count;
	int	len_curr_partition;

	// base case: size of medians is 1 or below
	if (ft_lstsize(*partitions) < 2)
		return ;

	// split
	// If median two first partitions are too far apart, get intermediate partition
	len_curr_partition = get_diff_partitions(*partitions, *stack_a);
	// push to b numbers that are between the 2 first medians. Loop until all expected number found
	ra_count = split_a(stack_a, stack_b, *partitions, len_curr_partition);
	// come back to initial position by checking the amount of ra instructions (unless half of the stack is in b)
	if (ft_lstsize(*stack_a) != ft_lstsize(*stack_b) && ft_lstsize(*stack_a) + 1 != ft_lstsize(*stack_b))
		while (ra_count--)
			rev_rotate_stack_print(stack_a, "rra");

	// sort
	if (ft_lstsize(*stack_b) <= MAX_STACK_INCREMENT)
	{
		// merge b into a in order
		merge_b_into_a_ordering(stack_a, stack_b);
		// delete first median
		ft_lstdel_first(partitions, ft_lstdel_int);
	}
	else
	{
		// merge b into a with partitions
		merge_b_into_a_partitioning(stack_a, stack_b, partitions, ft_lstsize(*stack_b));
		// sort medians
		ft_lst_sort(partitions, ascending);
		ft_lstdel_first(partitions, ft_lstdel_int);
	}

	// recursive call
	sort_stack_large(stack_a, stack_b, partitions);
	// rotate until sorted
	rotate_until_sorted(stack_a);
	// clean medians llist
	ft_lstclear(partitions, ft_lstdel_int);
	// return
}
