/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:05 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/06 10:06:28 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	head = (*stack)->next;
	(*stack)->next = NULL;
	*stack = head;
	return (1);
}

int	ra(t_list **a)
{
	if (!rotate(a))
		return (0);
	return (1);
}

int	rb(t_list **b)
{
	if (!rotate(b))
		return (0);
	return (1);
}

int	rr(t_list **a, t_list **b)
{
	if (!rotate(a))
		return (0);
	if (!rotate(b))
		return (0);
	return (1);
}
