/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:15:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/09 14:10:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_STACK_H
# define GET_STACK_H

# include "utils.h"

static int	is_int(char *stack_item);
static int	is_bigger_than_int(long long nb, char *item);
static int	is_all_zeros(char *item);
static int	has_duplicates(t_list *stack);

#endif
