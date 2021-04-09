/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 15:56:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Check if the list of instructions is correctly sorting the stack
** @param:	- [int] nb of arguments
**			- [char **] stack as a array of strings
** @return:	[int] return_value
** Line-by-line comments:
** @8		Converting to int makes it much easier to work with the stacks
** 			We only convert it after making sure that the instructions are valid
** 			so that we don't have to malloc and free an array of int for nothing
*/

int	main(int argc, char *argv[])
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;

	instructions = 0;
	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
		return (1);
	get_stack(argv + 1, argc - 1, &stack_a);
	ft_lst_print_d(stack_a);
	get_instructions(&instructions, &stack_a, &stack_b);
	// ft_lst_print_s(instructions);
	exec_instructions(instructions, &stack_a, &stack_b);
	// if (is_sorted(stack))
		// printf("OK\n");
	// else
	// 	printft("KO\n");
	ft_exit(0, &stack_a, &stack_b, &instructions);
}

/*
** Get instructions from stdin and stores them in a linked list
** @param:	- [type] param_value
**			- [type] param_value
** @return:	[type] return_value
** Line-by-line comments:
** @line-line	comment
*/

static void	get_instructions(t_list **instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	char	*line;
	t_list	*tmp;

	while (get_next_line(1, &line))
	{
		if (!is_instruction_valid(line))
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		tmp = ft_lstnew((void *)line);
		if (!tmp)
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		ft_lstadd_back(instructions, tmp);
	}
	free(line);
}

static int	is_instruction_valid(char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		return (1);
	else if (!ft_strcmp(instruction, "sb"))
		return (1);
	else if (!ft_strcmp(instruction, "ss"))
		return (1);
	else if (!ft_strcmp(instruction, "pa"))
		return (1);
	else if (!ft_strcmp(instruction, "pb"))
		return (1);
	else if (!ft_strcmp(instruction, "ra"))
		return (1);
	else if (!ft_strcmp(instruction, "rb"))
		return (1);
	else if (!ft_strcmp(instruction, "rr"))
		return (1);
	else if (!ft_strcmp(instruction, "rra"))
		return (1);
	else if (!ft_strcmp(instruction, "rrb"))
		return (1);
	else if (!ft_strcmp(instruction, "rrr"))
		return (1);
	else
		return (0);
}

static void	exec_instructions(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	while (instructions)
	{
		ft_lst_print_d(*stack_a);
		ft_lst_print_d(*stack_b);

		if (!ft_strcmp((char *)instructions->content, "sa"))
			stack_swap(stack_a);
		else if (!ft_strcmp((char *)instructions->content, "sb"))
			stack_swap(stack_b);
		else if (!ft_strcmp((char *)instructions->content, "ss"))
		{
			stack_swap(stack_a);
			stack_swap(stack_b);
		}

		ft_lst_print_d(*stack_a);
		ft_lst_print_d(*stack_b);

		instructions = instructions->next;
	}
}
