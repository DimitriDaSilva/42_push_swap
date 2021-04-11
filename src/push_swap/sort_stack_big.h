/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:08:36 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/11 22:24:59 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_BIG_H
# define SORT_STACK_BIG_H

# include "sort_stack.h"

static void	split_in_two_w_median(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int half_len);
static void	merge_b_into_a(t_list **stack_a,
				t_list ** stack_b,
				int median,
				int half_len);

#endif
