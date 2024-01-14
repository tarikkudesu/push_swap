/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:07:21 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 12:43:12 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	loop_rrr_a(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest->data != (*b)->data
		&& cheapest->target->data != (*a)->data)
		if (!rrr(a, b))
			return (0);
	while (cheapest->data != (*b)->data)
		if (!rrb(b))
			return (0);
	while (cheapest->target->data != (*a)->data)
		if (!rra(a))
			return (0);
	return (1);
}

int	loop_rr_a(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest->data != (*b)->data
		&& cheapest->target->data != (*a)->data)
		if (!rr(a, b))
			return (0);
	while (cheapest->data != (*b)->data)
		if (!rb(b))
			return (0);
	while (cheapest->target->data != (*a)->data)
		if (!ra(a))
			return (0);
	return (1);
}

int	loopsingle_a(t_list **a, t_list **b, t_list *cheapest)
{
	if (cheapest->med)
	{
		while (cheapest->data != (*b)->data)
			if (!rb(b))
				return (0);
	}
	else
	{
		while (cheapest->data != (*b)->data)
			if (!rrb(b))
				return (0);
	}
	if (cheapest->target->med)
	{
		while (cheapest->target->data != (*a)->data)
			if (!ra(a))
				return (0);
	}
	else
	{
		while (cheapest->target->data != (*a)->data)
			if (!rra(a))
				return (0);
	}
	return (1);
}

t_list	*find_target_a(int data, t_list **stack)
{
	t_list	*tmp;
	t_list	*target;

	tmp = *stack;
	target = tmp;
	while (tmp)
	{
		if (tmp->data > data)
		{
			target = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->data > data && tmp->data < target->data)
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

int	move_cheapest_a(t_list **a, t_list **b, t_list *cheapest)
{
	if (!cheapest->med && !cheapest->target->med)
	{
		if (!loop_rrr_a(a, b, cheapest))
			return (0);
	}
	else if (cheapest->med && cheapest->target->med)
	{
		if (!loop_rr_a(a, b, cheapest))
			return (0);
	}
	else
	{
		if (!loopsingle_a(a, b, cheapest))
			return (0);
	}
	return (1);
}
