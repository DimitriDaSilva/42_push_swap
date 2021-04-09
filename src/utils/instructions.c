/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 12:32:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	stack_swap(int **stack, int len)
{
	int	tmp;

	if (len <= 1)
		return ;
	tmp = **stack;
	**stack = *(*stack + 1);
	*(*stack + 1) = tmp;
}

void	stack_push(t_stacks *stacks, int len)
{

}
