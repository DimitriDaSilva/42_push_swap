/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:21:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/11 22:24:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_H
# define SORT_STACK_H

#include "push_swap.h"

void	sort_stack_small(t_list **stack_a);
void	sort_stack_big(t_list **stack_a, t_list **stack_b, int len);

#endif
