/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:09:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 09:37:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

/*
** Exits program and frees or displays message based on the exit code
** @param:	- [int] possible exit codes:
						-1 = crashed during first malloc so nothing to free
						0 = success. Program rechead end. Everything to free
						1 = 
**			- [int *] stack A. Just need to free it, so len not needed
**			- [int *] stack B. Just need to free it, so len not needed
**			- [char **] instructions. NULL terminated array of strings
** Line-by-line comments:
** @line-line	comment
*/

void	ft_exit(int exit_code, int *stack_a, int *stack_b, char **instructions)
{
	int	ret;

	if (exit_code == 0)
	{
		free(stack_a);
		free(stack_b);
		free_arr((void **)instructions);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (exit_code >= 1)
			free(stack_a);
		if (exit_code >= 2)
			free(stack_b);
		if (exit_code >= 3)
			free_arr((void **)instructions);
		ret = write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
		(void)ret;
	}
}
