/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 17:58:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	// char	**instructions;
	// int		*stack;

	if (argc == 1)
		return (1);
	check_stack_validity(argc, argv);
	// instructions = get_instructions();
	// stack = convert_to_ints(argv);
	// execute_instructions(stack, instructions);
	// if (is_sorted(stack))
	// 	printft("OK\n");
	// else
	// 	printft("KO\n");
	// free(stack);
	return (0);
}
