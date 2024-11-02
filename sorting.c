/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:43 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:04:46 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_be_continue(t_stack *a, int index, t_list *last)
{
	if (index == 1)
	{
		if (a->stack->content > last->content)
			ra(a);
		else
			sa(a);
	}
	else if (index == 2)
	{
		if (a->stack->content > a->stack->next->content)
		{
			sa(a);
			rra(a);
		}
		else
			rra(a);
	}
}

void	sort_three(t_stack *a)
{
	int		index;
	t_list	*last;

	if (!ft_sorted(a))
		return ;
	last = ft_lstlast(a->stack);
	index = ft_index(a, ft_min(a));
	if (index == 0)
	{
		sa(a);
		ra(a);
	}
	else
		to_be_continue(a, index, last);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	index;

	if (!ft_sorted(a))
		return ;
	a->size = ft_lstsize(a->stack);
	index = ft_index(a, ft_min(a));
	if (index <= a->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < a->size)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	index;

	a->size = ft_lstsize(a->stack);
	index = ft_index(a, ft_min(a));
	if (index <= a->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < a->size)
			rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
