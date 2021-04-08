/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_found.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:09:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 21:14:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_found.h"

void	error_found(int error_code, int *stack_a)
{
	int	ret;

	if (error_code == 1)
		free(stack_a);
	ret = write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
	(void)ret;
}
