/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_medium.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:08:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/12 14:57:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_MEDIUM_H
# define SORT_STACK_MEDIUM_H

# include "sort_stack.h"

static void	split_a_in_two_w_median(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int (*cmp)(int, int));
static void	merge_b_into_a(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int half_len);
static void	rotate_until_sorted(t_list **stack);

#endif
