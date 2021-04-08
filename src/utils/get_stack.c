/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:31:51 by dda-silv          #+#    #+#             */
/*   Updated: 2021/04/08 23:22:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_stack.h"

int	*get_stack(int len, char *stack[])
{
	int			*arr;
	int			i;
	long long	tmp;

	arr = malloc(len * sizeof(int));
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len)
	{
		if (!is_int(stack[i]))
			error_found(1, arr);
		tmp = ft_atoi(stack[i]);
		if (is_bigger_than_int(tmp, stack[i]))
			error_found(1, arr);
		arr[i] = tmp;
		i++;
	}
	if (has_duplicates(arr, len))
		error_found(1, arr);
	return (arr);
}

/*
** Checks if a stack item has non-digits characters
** @param:	- [char *] stack_item. If valid, it's a string formated int
** @return:	[int] true or false
** Line-by-line comments:
** @4		If items starts with '-' it could simply be a negative number.
**			Compound if statement wouldn't work here because I need it to not
**			execute condition line 9 if it starts with a '-'
** @6		If so, then start looking for non-digit characters after '-'
*/

static int	is_int(char *stack_item)
{
	int	check;

	check = 1;
	if (*stack_item == '-')
	{
		if (!ft_strisdigit(stack_item + 1))
			check = 0;
	}
	else if (!ft_strisdigit(stack_item))
		check = 0;
	return (check);
}

/*
** @param:	- [long long] number just converted from string
**			- [char *] we still need the string to check for an edge case
** @return:	[int] true or false
** Line-by-line comments:
** @6-7		In the case where number is above LLONG_MAX or bellow LLONG_MIN
**			ft_atoi returns 0. So, we need to check that if the nb value is 0
**			it's because the stack item was actually 0 or something like 00000
*/

static int	is_bigger_than_int(long long nb, char *item)
{
	int	check;

	check = 0;
	if (nb < INT_MIN || INT_MAX < nb)
		check = 1;
	if (nb == 0 && !is_all_zeros(item))
		check = 1;
	return (check);
}

static int	is_all_zeros(char *item)
{
	if (*item == '-')
		item++;
	while (*item)
	{
		if (*item++ != '0')
			return (0);
	}
	return (1);
}

static int	has_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (i != j && arr[i] == arr[j])
				return (1);
		}
	}
	return (0);
}
