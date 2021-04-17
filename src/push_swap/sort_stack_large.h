/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_large.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:45:28 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/17 18:28:22 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_LARGE_H
# define SORT_STACK_LARGE_H

# define MAX_STACK_INCREMENT 12

# include "sort_stack.h"

static void	merge_b_into_a_w_median(t_list **stack_a,
				t_list **stack_b,
				int old_len,
				t_list **medians);
static void	sort_half_stack_a(t_list **stack_a,
				t_list **stack_b,
				t_list **medians);
// static int	limit_stack_increment(t_list *medians, t_list *stack_a, int is_prev_inc_changed);
static int	is_first_node_a_sorted(t_list *stack_a, t_list *stack_b);
static void	merge_b_into_a_in_order(t_list **stack_a, t_list **stack_b);
static int	is_min_max_closer_to_top(t_list *stack, int min, int max);

#endif
