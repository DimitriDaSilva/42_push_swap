/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_medium.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 08:44:47 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 08:56:14 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_STACK_MEDIUM_H
# define SORT_STACK_MEDIUM_H

# include "sort_stack.h"

static void	split_a_in_two_w_median_medium(t_list **stack_a,
				t_list **stack_b,
				int median,
				int (*cmp)(int, int));
static int	is_closer_to_top_medium(t_list *stack, int median, int (*cmp)(int, int));
static void	merge_b_into_a_medium(t_list **stack_a,
				t_list **stack_b,
				int half_len);


#endif
