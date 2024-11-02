/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:56 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:04:58 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_stack *stack, t_stack *b)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			(free_s(stack->s), print_err(stack, b));
		i++;
	}
	return (result * sign);
}

void	ft_easy_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;
	int	size;

	i = 0;
	size = ft_lstsize(stack->stack);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (stack->arr[j] > stack->arr[j + 1])
			{
				tmp = stack->arr[j];
				stack->arr[j] = stack->arr[j + 1];
				stack->arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_index(t_stack *stack, int num)
{
	int		index;
	t_list	*tmp;

	tmp = stack->stack;
	index = 0;
	while (tmp)
	{
		if (num == tmp->content)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	ft_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack->stack;
	max = stack->stack->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack->stack;
	min = stack->stack->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
