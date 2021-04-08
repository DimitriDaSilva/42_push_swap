/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_validity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:48:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 18:38:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_stack_validity.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	check_stack_validity(int len, char *stack[])
{
	int	i;
	int	ret;

	i = 1;
	while (i < len)
	{
		if (!is_valid(stack[i]))
		{
			ret = write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	};
	(void)ret;
}

static int	is_valid(char *stack_item)
{
	(void)stack_item;
	printf("Arg: %s\n", stack_item);
	return (1);
}
