/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:56:40 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 12:43:50 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	loop_rrr_b(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest->data != (*a)->data
		&& cheapest->target->data != (*b)->data)
		if (!rrr(a, b))
			return (0);
	while (cheapest->data != (*a)->data)
		if (!rra(a))
			return (0);
	while (cheapest->target->data != (*b)->data)
		if (!rrb(b))
			return (0);
	return (1);
}

int	loop_rr_b(t_list **a, t_list **b, t_list *cheapest)
{
	while (cheapest->data != (*a)->data
		&& cheapest->target->data != (*b)->data)
		if (!rr(a, b))
			return (0);
	while (cheapest->data != (*a)->data)
		if (!ra(a))
			return (0);
	while (cheapest->target->data != (*b)->data)
		if (!rb(b))
			return (0);
	return (1);
}

int	loopsingle_b(t_list **a, t_list **b, t_list *cheapest)
{
	if (cheapest->med)
	{
		while (cheapest->data != (*a)->data)
			if (!ra(a))
				return (0);
	}
	else
	{
		while (cheapest->data != (*a)->data)
			if (!rra(a))
				return (0);
	}
	if (cheapest->target->med)
	{
		while (cheapest->target->data != (*b)->data)
			if (!rb(b))
				return (0);
	}
	else
	{
		while (cheapest->target->data != (*b)->data)
			if (!rrb(b))
				return (0);
	}
	return (1);
}

t_list	*find_target_b(int data, t_list **stack)
{
	t_list	*tmp;
	t_list	*target;

	tmp = *stack;
	target = tmp;
	while (tmp)
	{
		if (tmp->data < data)
		{
			target = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->data < data && tmp->data > target->data)
			target = tmp;
		tmp = tmp->next;
	}
	return (target);
}

int	move_cheapest_b(t_list **a, t_list **b, t_list *cheapest)
{
	if (!cheapest->med && !cheapest->target->med)
	{
		if (!loop_rrr_b(a, b, cheapest))
			return (0);
	}
	else if (cheapest->med && cheapest->target->med)
	{
		if (!loop_rr_b(a, b, cheapest))
			return (0);
	}
	else
	{
		if (!loopsingle_b(a, b, cheapest))
			return (0);
	}
	return (1);
}
