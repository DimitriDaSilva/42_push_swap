/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:25:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/20 14:13:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_instructions.h"

void	get_instructions(t_list **instructions,
			t_list **stack_a,
			t_list **stack_b)
{
	char	*line;
	t_list	*tmp;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!is_instruction_valid(line))
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		tmp = ft_lstnew((void *)line);
		if (!tmp)
		{
			free(line);
			ft_exit(2, stack_a, stack_b, instructions);
		}
		ft_lstadd_back(instructions, tmp);
	}
	free(line);
}

static int	is_instruction_valid(char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		return (1);
	else if (!ft_strcmp(instruction, "sb"))
		return (1);
	else if (!ft_strcmp(instruction, "ss"))
		return (1);
	else if (!ft_strcmp(instruction, "pa"))
		return (1);
	else if (!ft_strcmp(instruction, "pb"))
		return (1);
	else if (!ft_strcmp(instruction, "ra"))
		return (1);
	else if (!ft_strcmp(instruction, "rb"))
		return (1);
	else if (!ft_strcmp(instruction, "rr"))
		return (1);
	else if (!ft_strcmp(instruction, "rra"))
		return (1);
	else if (!ft_strcmp(instruction, "rrb"))
		return (1);
	else if (!ft_strcmp(instruction, "rrr"))
		return (1);
	else
		return (0);
}
