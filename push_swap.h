/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:04:12 by abel-baz          #+#    #+#             */
/*   Updated: 2024/06/05 11:04:15 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*stack;
	char			**s;
	int				range;
	int				*arr;
	int				size;
	int				min;
	int				i;
	int				j;
}					t_stack;

t_stack				*ft_init(void);
int					ft_sorted(t_stack *stack);
void				ft_input(t_stack *stack, t_stack *b, char **av);
int					ft_atoi(char *str, t_stack *stack, t_stack *b);
void				sort_three(t_stack *a);
int					ft_index(t_stack *stack, int num);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);
void				to_be_continue(t_stack *a, int min, t_list *last);
void				sort_five(t_stack *a, t_stack *b);
void				sort_four(t_stack *a, t_stack *b);
void				ft_easy_sort(t_stack *stack);
void				sort_chunks(t_stack *a, t_stack *b);
int					is_int(char *s);
char				**ft_split(char const *s, char c, t_stack *stack,
						t_stack *b);
void				free_s(char **str);
void				free_allocs(t_stack *a, t_stack *b);
void				print_err(t_stack *a, t_stack *b);
int					is_dup(t_stack *stack);

void				sa(t_stack *stack);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *stack);
void				rra(t_stack *stack);
void				pb(t_stack *a, t_stack *b);
void				rb(t_stack *stack);
void				rrb(t_stack *stack);

t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
