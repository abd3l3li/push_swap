/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:03:55 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:03:57 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = NULL;
	stack->s = NULL;
	stack->range = 0;
	stack->arr = 0;
	stack->min = 0;
	stack->i = 0;
	stack->j = 0;
	return (stack);
}

void	get_arr(t_stack *stack, t_stack *b)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 0;
	tmp = stack->stack;
	size = ft_lstsize(stack->stack);
	stack->arr = malloc(size * sizeof(int));
	if (!stack->arr)
		return ;
	while (tmp)
	{
		stack->arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_easy_sort(stack);
	if (is_dup(stack))
		print_err(stack, b);
}

void	ft_input(t_stack *stack, t_stack *b, char **av)
{
	while (av[stack->i])
	{
		stack->s = ft_split(av[stack->i], ' ', stack, b);
		if (stack->s[0] == NULL)
		{
			free_s(stack->s);
			print_err(stack, b);
		}
		stack->j = 0;
		while (stack->s[stack->j])
		{
			if (!is_int(stack->s[stack->j]))
			{
				free_s(stack->s);
				print_err(stack, b);
			}
			ft_lstadd_back(&stack->stack,
				ft_lstnew(ft_atoi(stack->s[stack->j], stack, b)));
			stack->j++;
		}
		stack->i++;
		free_s(stack->s);
	}
	get_arr(stack, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	a = ft_init();
	b = ft_init();
	ft_input(a, b, av + 1);
	a->size = ft_lstsize(a->stack);
	if (!ft_sorted(a))
	{
		free_allocs(a, b);
		exit(0);
	}
	else if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
	else if (a->size == 4)
		sort_four(a, b);
	else
		sort_chunks(a, b);
	free_allocs(a, b);
}
