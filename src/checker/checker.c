/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 12:33:15 by dda-silv         ###   ########.fr       */
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
	t_list		*instructions;
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	stacks.len = argc - 1;
	stacks.a = get_stack(stacks.len, argv + 1);
	stacks.b = ft_calloc(stacks.len, sizeof(int));
	if (!stacks.b)
		ft_exit(1, stacks.a, 0, 0);
	// print_arr_int(stacks.a, stacks.len);
	instructions = 0;
	get_instructions(&instructions, &stacks);
	// ft_lst_print_s(instructions);
	exec_instructions(instructions, &stacks);
	// if (is_sorted(stack))
		// printf("OK\n");
	// else
	// 	printft("KO\n");
	ft_exit(0, stacks.a, stacks.b, &instructions);
}

/*
** Get instructions from stdin and stores them in a linked list
** @param:	- [type] param_value
**			- [type] param_value
** @return:	[type] return_value
** Line-by-line comments:
** @line-line	comment
*/

static void	get_instructions(t_list **instructions, t_stacks *stacks)
{
	char	*line;
	t_list	*tmp;

	while (get_next_line(1, &line))
	{
		if (!is_instruction_valid(line))
		{
			free(line);
			ft_exit(2, stacks->a, stacks->b, instructions);
		}
		tmp = ft_lstnew((void *)line);
		if (!tmp)
		{
			free(line);
			ft_exit(2, stacks->a, stacks->b, instructions);
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

static void	exec_instructions(t_list *instructions, t_stacks *stacks)
{
	while (instructions)
	{
		print_arr_int(stacks->a, stacks->len);
		print_arr_int(stacks->b, stacks->len);

		if (!ft_strcmp((char *)instructions->content, "sa"))
			stack_swap(&stacks->a, stacks->len);
		else if (!ft_strcmp((char *)instructions->content, "sb"))
			stack_swap(&stacks->b, stacks->len);
		else if (!ft_strcmp((char *)instructions->content, "ss"))
		{
			stack_swap(&stacks->a, stacks->len);
			stack_swap(&stacks->b, stacks->len);
		}

		print_arr_int(stacks->a, stacks->len);
		print_arr_int(stacks->b, stacks->len);
		instructions = instructions->next;
	}
}
