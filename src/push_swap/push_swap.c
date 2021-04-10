/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:53:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/10 20:42:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	mode;

	stack_a = 0;
	stack_b = 0;
	mode = '\0';
	if (argc == 1 || (argc == 2 && !ft_strcmp(argv[1], "-v")))
		return (1);
	if (!ft_strcmp(argv[1], "-v"))
		mode = 'v';
	if (!ft_strcmp(argv[1], "-v"))
		get_stack(argv + 2, argc - 2, &stack_a);
	else
		get_stack(argv + 1, argc - 1, &stack_a);
	// ft_lst_print_d(stack_a);
	printf("ra\n");
	printf("ra\n");
	sort_stack(&stack_a, &stack_b);
	ft_exit(0, &stack_a, &stack_b, 0);
	(void)mode;
}
