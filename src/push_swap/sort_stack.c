/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:21:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/18 15:49:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_stack.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int		len;
	t_list	**medians;


	*medians = 0;
	ft_lstadd_front(medians, ft_lstnew((void *)ft_lst_get_max(*stack_a)));
	// ft_lstadd_front(medians, ft_lstnew((void *)ft_lst_get_median(*stack_a)));
	ft_lstadd_front(medians, ft_lstnew((void *)ft_lst_get_min(*stack_a)));
	len = ft_lstsize(*stack_a);
	if (len <= 1)
		return ;
	else if (len <= 3)
		sort_stack_small(stack_a);
	else if (len <= 5)
		sort_stack_medium(stack_a, stack_b);
	else
		sort_stack_large(stack_a, stack_b, medians, len);
}
