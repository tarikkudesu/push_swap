/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:25:45 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/15 17:44:25 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	cost_to_top(t_list **stack, t_list **cur)
{
	unsigned int	size;

	size = ft_lstsize(*stack);
	if ((*cur)->position < size / 2)
		return ((*cur)->position);
	else
		return (size - (*cur)->position);
}

unsigned int	max(unsigned int x, unsigned int y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

t_list	*find_cheapest(t_list **a)
{
	t_list	*tmp;
	t_list	*cheapest;

	cheapest = *a;
	tmp = (*a)->next;
	while (tmp)
	{
		if (tmp->cheap < cheapest->cheap)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

int	is_sorted(t_list **stack_a)
{
	t_list			*tmp;

	if (!(stack_a) || !(*stack_a)->next)
		return (1);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		exit(1);
	}
	if (size <= 5)
		simple_sort(stack_a, stack_b, size);
	else
	{
		sort_to_b(stack_a, stack_b);
		sort_to_a(stack_a, stack_b);
	}
	return ;
}
