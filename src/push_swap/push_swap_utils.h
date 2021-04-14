/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:35:31 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/14 16:44:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "utils.h"
# include "instructions.h"
# include "instructions_print.h"

void	split_a_in_two_w_median(t_list **stack_a,
			t_list **stack_b,
			int median,
			int (*cmp)(int, int));
void	merge_b_into_a(t_list **stack_a,
			t_list **stack_b,
			int half_len);
void	rotate_until_sorted(t_list **stack);

#endif
