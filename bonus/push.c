/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:01 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/06 10:06:38 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*head_to;
	t_list	*head_from;
	t_list	*tmp;

	if (!ft_lstsize(*stack_from))
		return (0);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = tmp;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (1);
}

int	pa(t_list **a, t_list **b)
{
	if (!push(a, b))
		return (0);
	return (1);
}

int	pb(t_list **a, t_list **b)
{
	if (!push(b, a))
		return (0);
	return (1);
}
