/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:09:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/05/14 12:47:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Exits program and frees or displays message based on the exit code
** @param:	- [int] possible exit codes:
						-1 = crashed during first malloc so nothing to free
						0 = success. Program rechead end. Everything to free and
							nothing to print
						1 = crashed during the malloc of stack b
						2 = crashed during get_instructions
**			- [int *] stack A. Just need to free it, so len not needed
**			- [int *] stack B. Just need to free it, so len not needed
**			- [char **] instructions. NULL terminated array of strings
*/

void	ft_exit(int exit_code,
		t_list **stack_a,
		t_list **stack_b,
		t_list **instructions)
{
	if (exit_code == 0)
	{
		ft_lstclear(stack_a, ft_lstdel_int);
		ft_lstclear(stack_b, ft_lstdel_int);
		ft_lstclear(instructions, free);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			ft_lstclear(stack_a, ft_lstdel_int);
		if (exit_code >= 2)
		{
			ft_lstclear(stack_b, ft_lstdel_int);
			ft_lstclear(instructions, free);
		}
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	print_stacks(char *instruction,	t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	printf("----------------\n%s:\n\n", instruction);
	while (len_a >= 0 && len_b >= 0)
		print_stack(&stack_a, &len_a, &stack_b, &len_b);
	printf("   ___    ___\n    A      B\n");
}

void	print_stack(t_list **stack_a, int *len_a, t_list **stack_b, int *len_b)
{
	if (*len_a > *len_b && (*len_a)--)
	{
		printf("  % -5ld\n", (long)(*stack_a)->data);
		*stack_a = (*stack_a)->next;
	}
	else if (*len_a < *len_b && (*len_b)--)
	{
		printf("         % -5ld\n", (long)(*stack_b)->data);
		*stack_b = (*stack_b)->next;
	}
	else if ((*len_a)-- && (*len_b)--)
	{
		printf("  % -5ld", (long)(*stack_a)->data);
		printf("  % -5ld\n", (long)(*stack_b)->data);
		*stack_a = (*stack_a)->next;
		*stack_b = (*stack_b)->next;
	}
}

int	is_sorted(t_list *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		tmp = (long)stack->data;
		stack = stack->next;
		if (tmp >= (long)stack->data)
			return (0);
	}
	return (1);
}
