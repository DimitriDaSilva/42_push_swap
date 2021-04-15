/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_large.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:49:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 08:50:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_LARGE_H
# define SORT_STACK_LARGE_H

# include "sort_stack.h"

static void	merge_b_into_a_w_median(t_list **stack_a,
				t_list **stack_b,
				int median,
				int (*cmp)(int, int));

#endif
