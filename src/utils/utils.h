/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:16:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/15 15:30:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./../../libft/src/libft.h"

void	ft_exit(int exit_code,
			t_list **stack_a,
			t_list **stack_b,
			t_list **instructions);
void	print_stacks(char *instruction,	t_list *stack_a, t_list *stack_b);
void	print_stack(t_list **stack_a, int *len_a, t_list **stack_b, int *len_b);
int		is_sorted(t_list *stack);

#endif
