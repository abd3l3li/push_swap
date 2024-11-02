/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 02:23:17 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/06 02:23:23 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (!stack->stack || !stack->stack->next)
		return ;
	tmp = stack->stack->content;
	stack->stack->content = stack->stack->next->content;
	stack->stack->next->content = tmp;
}

void	do_it(char *check, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa", check, 2) && (check[2] == '\n'))
		sa(a);
	else if (!ft_strncmp("sb", check, 2) && (check[2] == '\n'))
		sb(b);
	else if (!ft_strncmp("pb", check, 2) && (check[2] == '\n'))
		pb(a, b);
	else if (!ft_strncmp("pa", check, 2) && (check[2] == '\n'))
		pa(a, b);
	else if (!ft_strncmp("ra", check, 2) && (check[2] == '\n'))
		ra(a);
	else if (!ft_strncmp("rb", check, 2) && (check[2] == '\n'))
		rb(b);
	else if (!ft_strncmp("rra", check, 3) && (check[3] == '\n'))
		rra(a);
	else if (!ft_strncmp("rrb", check, 3) && (check[3] == '\n'))
		rrb(b);
	else if (!ft_strncmp("ss", check, 2) && (check[2] == '\n'))
		ss(a, b);
	else if (!ft_strncmp("rr", check, 2) && (check[2] == '\n'))
		rr(a, b);
	else if (!ft_strncmp("rrr", check, 3) && (check[3] == '\n'))
		rrr(a, b);
	else
		(get_next_line(-1), free(check), print_err(a, b));
}

void	one_more(t_stack *a, t_stack *b)
{
	char	*check;

	while (1)
	{
		check = get_next_line(0);
		if (!check)
			break ;
		do_it(check, a, b);
		free(check);
	}
	if (!ft_sorted(a) && !(b->stack))
	{
		free_allocs(a);
		free(b);
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		free_allocs(a);
		free_allocs2(b);
		write(1, "KO\n", 3);
		exit(0);
	}
}
