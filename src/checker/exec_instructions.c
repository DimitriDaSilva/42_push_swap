/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:29:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 16:49:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_instructions.h"

void	exec_instructions(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b,
			char mode)
{
	if (mode == 'v')
		print_stacks("Init", *stack_a, *stack_b);
	while (instructions)
	{
		if (*(char *)instructions->data == 's')
			exec_swap(instructions, stack_a, stack_b);
		else if (*(char *)instructions->data == 'p')
			exec_push(instructions, stack_a, stack_b);
		else if (ft_strlen((char *)instructions->data) == 2)
			exec_rotate(instructions, stack_a, stack_b);
		else
			exec_rev_rotate(instructions, stack_a, stack_b);
		if (mode == 'v')
			print_stacks((char *)instructions->data, *stack_a, *stack_b);
		instructions = instructions->next;
	}
}

static void	exec_swap(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->data, "sa"))
		swap_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->data, "sb"))
		swap_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->data, "ss"))
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
}

static void	exec_push(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->data, "pa"))
		push_stack(stack_a, stack_b);
	else if (!ft_strcmp((char *)instructions->data, "pb"))
		push_stack(stack_b, stack_a);
}

static void	exec_rotate(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->data, "ra"))
		rotate_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->data, "rb"))
		rotate_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->data, "rr"))
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
}

static void	exec_rev_rotate(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	if (!ft_strcmp((char *)instructions->data, "rra"))
		rev_rotate_stack(stack_a);
	else if (!ft_strcmp((char *)instructions->data, "rrb"))
		rev_rotate_stack(stack_b);
	else if (!ft_strcmp((char *)instructions->data, "rrr"))
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
	}
}
