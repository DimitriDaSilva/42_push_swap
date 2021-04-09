/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 15:53:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	stack_swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	if (!first_node || !first_node->next)
		return ;
	second_node = first_node->next;
	*stack = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
}

// void	stack_push(t_stacks *stacks, int len)
// {

// }
