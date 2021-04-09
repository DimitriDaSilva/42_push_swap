/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 19:16:14 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	swap_stack(t_list **stack)
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

void	push_stack(t_list **dest, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if (!tmp)
		return ;
	*src = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(dest, tmp);
}

void	rotate_stack(t_list **stack)
{
	t_list	*first_node;

	first_node = *stack;
	if (!first_node || !first_node->next)
		return ;
	*stack = first_node->next;
	first_node->next = 0;
	ft_lstadd_back(stack, first_node);
}

void	rev_rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*last_node;

	tmp = *stack;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last_node = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(stack, last_node);
}
