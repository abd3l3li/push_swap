/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:03:01 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:03:04 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(t_stack *stack)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(stack->stack);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->arr[i] == stack->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_sorted(t_stack *stack)
{
	t_list	*tmp;

	if (stack->stack == NULL)
		return (1);
	tmp = stack->stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
