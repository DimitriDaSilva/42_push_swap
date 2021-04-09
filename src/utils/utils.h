/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:16:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 12:27:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./../../libft/src/libft.h"

typedef struct s_stacks
{
	int			*a;
	int			*b;
	int			len;
}				t_stacks;

void	ft_exit(int exit_code,
		int *stack_a,
		int *stack_b,
		t_list **instructions);

#endif
