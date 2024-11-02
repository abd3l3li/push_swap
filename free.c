/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:03:20 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:03:27 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_allocs(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	tmp = a->stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(a->stack);
		a->stack = tmp;
	}
	if (a->arr)
		free(a->arr);
	if (a)
		free(a);
	if (b)
		free(b);
}

void	free_s(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_err(t_stack *a, t_stack *b)
{
	free_allocs(a, b);
	write(1, "Error\n", 6);
	exit(1);
}
