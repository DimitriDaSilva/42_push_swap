/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/20 17:20:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Check if the list of instructions is correctly sorting the stack
** @param:	- [int] nb of arguments
**			- [char **] stack as a array of strings
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
	char	mode;

	instructions = 0;
	stack_a = 0;
	stack_b = 0;
	mode = '\0';
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (1);
	if (!ft_strcmp(argv[1], "-v"))
		mode = 'v';
	if (!ft_strcmp(argv[1], "-v"))
		get_stack(argv + 2, argc - 2, &stack_a);
	else
		get_stack(argv + 1, argc - 1, &stack_a);
	get_instructions(&instructions, &stack_a, &stack_b);
	exec_instructions(instructions, &stack_a, &stack_b, mode);
	if (is_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	ft_exit(0, &stack_a, &stack_b, &instructions);
}
