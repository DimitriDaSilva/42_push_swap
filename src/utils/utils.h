/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 08:16:03 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 14:09:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./../../libft/src/libft.h"

void	ft_exit(int exit_code,
		t_list **stack_a,
		t_list **stack_b,
		t_list **instructions);

#endif
