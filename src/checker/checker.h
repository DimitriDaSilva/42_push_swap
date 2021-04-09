/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:55:56 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 19:24:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"
# include "instructions.h"

void	get_stack(char *stack[], int len, t_list **stack_a);
void	get_instructions(t_list **instructions,
			t_list **stack_a,
			t_list **stack_b);
void	exec_instructions(t_list *instructions,
			t_list **stack_a,
			t_list **stack_b,
			char mode);
int		is_sorted(t_list *stack);

#endif
