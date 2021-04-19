/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_print.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:41:28 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/19 12:27:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_PRINT_H
# define INSTRUCTIONS_PRINT_H

# include "utils.h"
# include "instructions.h"

void	swap_stack_print(t_list **stack, char *str);
void	push_stack_print(t_list **dest, t_list **src, char *str);
void	rotate_stack_print(t_list **stack, char *str);
void	double_rotate_stack_print(t_list **stack_a, t_list **stack_b);
void	rev_rotate_stack_print(t_list **stack, char *str);

#endif
