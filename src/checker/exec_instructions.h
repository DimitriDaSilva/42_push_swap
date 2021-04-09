/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:30:21 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 19:15:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_INSTRUCTIONS_H
# define EXEC_INSTRUCTIONS_H

# include "checker.h"

static void	exec_swap(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_push(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_rotate(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);
static void	exec_rev_rotate(t_list *instructions,
				t_list **stack_a,
				t_list **stack_b);

#endif
