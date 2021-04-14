/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:26 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 16:42:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions_print.h"

void	swap_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	swap_stack(stack);
}

void	push_stack_print(t_list **dest, t_list **src, char *str)
{
	printf("%s\n", str);
	push_stack(dest, src);
}

void	rotate_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	rotate_stack(stack);
}

void	rev_rotate_stack_print(t_list **stack, char *str)
{
	printf("%s\n", str);
	rev_rotate_stack(stack);
}
