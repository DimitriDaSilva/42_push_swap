/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:16:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/20 14:16:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"

# include "./../../libft/src/libft.h"

void	ft_exit(int exit_code,
			t_list **stack_a,
			t_list **stack_b,
			t_list **instructions);
void	print_stacks(char *instruction,	t_list *stack_a, t_list *stack_b);
void	print_stack(t_list **stack_a, int *len_a, t_list **stack_b, int *len_b);
int		is_sorted(t_list *stack);

#endif
