/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:14:36 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/15 17:44:04 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_min(int data, t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->data < data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

unsigned int	cheap_set_b(t_list **a, t_list **b, t_list **cur)
{
	if ((*cur)->med && (*cur)->target->med)
		return (max(cost_to_top(a, cur), cost_to_top(b, &(*cur)->target)));
	if (!(*cur)->med && !(*cur)->target->med)
		return (max(cost_to_top(a, cur), cost_to_top(b, &(*cur)->target)));
	else
		return ((cost_to_top(a, cur) + cost_to_top(b, &(*cur)->target)));
	return (0);
}

void	set_everything_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_set_positions(a);
	ft_set_positions(b);
	tmp = *a;
	while (tmp)
	{
		if (tmp->position < ft_lstsize(*a) / 2)
			tmp->med = 1;
		else
			tmp->med = 0;
		if (is_min(tmp->data, b))
			tmp->target = find_max(b);
		else
			tmp->target = find_target_b(tmp->data, b);
		if (tmp->target->position < ft_lstsize(*b) / 2)
			tmp->target->med = 1;
		else
			tmp->target->med = 0;
		tmp->cheap = cheap_set_b(a, b, &tmp);
		tmp = tmp->next;
	}
}

void	sort_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest;

	pb(a, b);
	pb(a, b);
	while (ft_lstsize(*a) > 3)
	{
		set_everything_b(a, b);
		cheapest = find_cheapest(a);
		move_cheapest_b(a, b, cheapest);
		pb(a, b);
	}
	if (!is_sorted(a))
		ft_sort3(a);
}
