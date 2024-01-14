/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:56:21 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 15:51:32 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_max(int data, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->data > data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data < max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

unsigned int	cheap_set_a(t_list **a, t_list **b, t_list **cur)
{
	if ((*cur)->med && (*cur)->target->med)
		return (max_value(cost_to_top(b, cur), cost_to_top(a, &(*cur)->target)));
	if (!(*cur)->med && !(*cur)->target->med)
		return (max_value(cost_to_top(b, cur), cost_to_top(a, &(*cur)->target)));
	else
		return ((cost_to_top(b, cur) + cost_to_top(a, &(*cur)->target)));
	return (0);
}

void	set_everything_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		ft_set_positions(a);
		ft_set_positions(b);
		if (tmp->position < ft_lstsize(*a) / 2)
			tmp->med = 1;
		else
			tmp->med = 0;
		if (is_max(tmp->data, b))
			tmp->target = find_min(b);
		else
			tmp->target = find_target_a(tmp->data, b);
		if (tmp->target->position < ft_lstsize(*a) / 2)
			tmp->target->med = 1;
		else
			tmp->target->med = 0;
		tmp->cheap = cheap_set_a(a, b, &tmp);
		tmp = tmp->next;
	}
}

void	sort_to_a(t_list **a, t_list **b)
{
	t_list	*cheapest;
	t_list	*min;

	while (*b)
	{
		set_everything_a(b, a);
		cheapest = find_cheapest(b);
		move_cheapest_a(a, b, cheapest);
		pa(a, b);
	}
	ft_set_positions(a);
	min = find_min(a);
	if (min->position < ft_lstsize(*a) / 2)
		while ((*a)->data != min->data)
			ra(a);
	else
		while ((*a)->data != min->data)
			rra(a);
}
