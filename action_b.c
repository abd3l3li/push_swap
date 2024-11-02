/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:02:36 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:02:44 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!a->stack)
		return ;
	tmp = a->stack;
	a->stack = tmp->next;
	tmp->next = b->stack;
	b->stack = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack->stack || !stack->stack->next)
		return ;
	first = stack->stack;
	stack->stack = stack->stack->next;
	first->next = NULL;
	last = ft_lstlast(stack->stack);
	last->next = first;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	t_list		*second;
	t_list		*last;

	if (!stack->stack || !stack->stack->next)
		return ;
	last = stack->stack;
	second = NULL;
	while (last->next)
	{
		second = last;
		last = last->next;
	}
	second->next = NULL;
	last->next = stack->stack;
	stack->stack = last;
	write(1, "rrb\n", 4);
}
