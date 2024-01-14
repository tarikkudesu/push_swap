/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:57 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/06 10:06:33 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*head;

	if (ft_lstsize(*stack) < 2)
		return (0);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	head = tmp->next;
	tmp->next = NULL;
	head->next = *stack;
	*stack = head;
	return (1);
}

int	rra(t_list **a)
{
	if (!reverse_rotate(a))
		return (0);
	return (1);
}

int	rrb(t_list **b)
{
	if (!reverse_rotate(b))
		return (0);
	return (1);
}

int	rrr(t_list **a, t_list **b)
{
	if (!reverse_rotate(a))
		return (0);
	if (!reverse_rotate(b))
		return (0);
	return (1);
}
