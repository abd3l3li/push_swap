/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:09:29 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/08 13:09:37 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!a->stack)
		return ;
	tmp = a->stack;
	a->stack = tmp->next;
	tmp->next = b->stack;
	b->stack = tmp;
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
}

void	rrb(t_stack *stack)
{
	t_list	*second;
	t_list	*last;

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
}
