/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 09:21:03 by dda-silv         ###   ########.fr       */
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
	char		**instructions;
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	stacks.a = get_stack(argc - 1, argv + 1);
	stacks.b = malloc((argc - 1) * sizeof(int));
	if (!stacks.b)
		ft_exit(1, stacks.a, 0, 0);
	print_arr_int(stacks.a, argc - 1);
	instructions = get_instructions();
	if (!instructions)
		ft_exit(2, stacks.a, stacks.b, 0);
	print_arr_str(instructions);
	// execute_instructions(stacks, instructions);
	// if (is_sorted(stack))
	// 	printft("OK\n");
	// else
	// 	printft("KO\n");
	ft_exit(0, stacks.a, stacks.b, instructions);
}

static char	**get_instructions(void)
{
	char	**instructions;
	char	*line;
	int		i;

	instructions = 0;
	instructions = ft_calloc(STDIN_FILENO, sizeof(char *));
	if (!instructions)
		return (0);
	i = 0;
	while (get_next_line(1, &line))
	{
		instructions[i++] = line;
		instructions = ft_realloc(instructions,
			i * sizeof(char *),
			(i + 1) * sizeof(char *));
		if (!instructions)
			return (0);
	}
	free(line);
	instructions[i] = 0;
	return (instructions);
}
