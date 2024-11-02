/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:11:20 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/08 13:11:22 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_allocs2(t_stack *b)
{
	t_list	*tmp;

	if (b)
	{
		tmp = b->stack;
		while (tmp)
		{
			tmp = tmp->next;
			free(b->stack);
			b->stack = tmp;
		}
	}
	free(b);
}

void	free_allocs(t_stack *a)
{
	t_list	*tmp;

	if (a)
	{
		tmp = a->stack;
		while (tmp)
		{
			tmp = tmp->next;
			free(a->stack);
			a->stack = tmp;
		}
	}
	if (a->arr)
		free(a->arr);
	free(a);
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
	free_allocs(a);
	free_allocs2(b);
	write(1, "Error\n", 6);
	exit(1);
}
