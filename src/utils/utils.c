/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:09:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 12:21:50 by dda-silv         ###   ########.fr       */
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
** Line-by-line comments:
** @line-line	comment
*/

void	ft_exit(int exit_code,
		int *stack_a,
		int *stack_b,
		t_list **instructions)
{
	int	ret;

	if (exit_code == 0)
	{
		free(stack_a);
		free(stack_b);
		ft_lstclear(instructions, free);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			free(stack_a);
		if (exit_code >= 2)
		{
			free(stack_b);
			ft_lstclear(instructions, free);
		}
		ret = write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
		(void)ret;
	}
}

