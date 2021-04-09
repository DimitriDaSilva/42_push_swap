/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:09:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 18:26:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	del(void *data)
{
	(void)data;
}

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
** Line-by-line comments:
** @line-line	comment
*/

void	ft_exit(int exit_code,
		t_list **stack_a,
		t_list **stack_b,
		t_list **instructions)
{
	int	ret;

	if (exit_code == 0)
	{
		ft_lstclear(stack_a, del);
		ft_lstclear(stack_b, del);
		ft_lstclear(instructions, free);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			ft_lstclear(stack_a, del);
		if (exit_code >= 2)
		{
			ft_lstclear(stack_b, del);
			ft_lstclear(instructions, free);
		}
		ret = write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
		(void)ret;
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
		printf("  % -5ld\n", (long int)(*stack_a)->data);
		*stack_a = (*stack_a)->next;
	}
	else if (*len_a < *len_b && (*len_b)--)
	{
		printf("         % -5ld\n", (long int)(*stack_b)->data);
		*stack_b = (*stack_b)->next;
	}
	else if ((*len_a)-- && (*len_b)--)
	{
		printf("  % -5ld", (long int)(*stack_a)->data);
		printf("  % -5ld\n", (long int)(*stack_b)->data);
		*stack_a = (*stack_a)->next;
		*stack_b = (*stack_b)->next;
	}
}
