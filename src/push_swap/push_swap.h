/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:55:56 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/19 19:14:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_utils.h"

void	get_stack(char *stack[], int len, t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_stack_small(t_list **stack_a);
void	sort_stack_medium(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions);
void	sort_stack_large(t_list **stack_a,
			t_list **stack_b,
			t_list **partitions);

#endif
