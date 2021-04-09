/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:11:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 19:16:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "utils.h"

void	swap_stack(t_list **stack);
void	push_stack(t_list **dest, t_list **src);
void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);

#endif
