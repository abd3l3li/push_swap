/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chucnk_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:13:04 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/08 13:13:08 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_max(t_stack *a, t_stack *b)
{
	int	index;
	int	size;

	size = ft_lstsize(b->stack);
	index = ft_index(b, ft_max(b));
	if (index <= size / 2)
		while (b->stack->content != ft_max(b))
			rb(b);
	else
		while (b->stack->content != ft_max(b))
			rrb(b);
	pa(a, b);
}

int	set_range(t_stack *stack)
{
	int	range;

	if (stack->size <= 16)
		range = 5;
	else if (stack->size <= 100)
		range = 15;
	else
		range = 40;
	return (range);
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	a->range = set_range(a);
	a->size = ft_lstsize(a->stack);
	while (a->stack)
	{
		if (a->stack->content >= a->arr[a->min]
			&& a->stack->content <= a->arr[a->range])
		{
			pb(a, b);
			if (a->range < a->size - 1)
				a->range++;
			a->min++;
		}
		else if (a->stack->content < a->arr[a->min])
		{
			pb(a, b);
			rb(b);
			if (a->range < a->size - 1)
				a->range++;
			a->min++;
		}
		else
			ra(a);
	}
	while (b->stack)
		push_max(a, b);
}
