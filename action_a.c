/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:02:16 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:02:26 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (!b->stack)
		return ;
	tmp = b->stack;
	b->stack = tmp->next;
	tmp->next = a->stack;
	a->stack = tmp;
	write(1, "pa\n", 3);
}

void	sa(t_stack *stack)
{
	int	tmp;

	if (!stack->stack || !stack->stack->next)
		return ;
	tmp = stack->stack->content;
	stack->stack->content = stack->stack->next->content;
	stack->stack->next->content = tmp;
	write(1, "sa\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rra\n", 4);
}
