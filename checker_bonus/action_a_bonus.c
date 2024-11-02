/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:08:58 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/08 13:09:06 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!b->stack)
		return ;
	tmp = b->stack;
	b->stack = tmp->next;
	tmp->next = a->stack;
	a->stack = tmp;
}

void	sa(t_stack *stack)
{
	int	tmp;

	if (!stack->stack || !stack->stack->next)
		return ;
	tmp = stack->stack->content;
	stack->stack->content = stack->stack->next->content;
	stack->stack->next->content = tmp;
}

void	ra(t_stack *stack)
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

void	rra(t_stack *stack)
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
