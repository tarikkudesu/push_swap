/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:08 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/06 10:11:08 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_swap(t_list **a)
{
	int	d;

	if (ft_lstsize(*a) <= 1)
		return (0);
	d = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = d;
	return (1);
}

int	sa(t_list **a)
{
	if (!ft_swap(a))
		return (0);
	return (1);
}

int	sb(t_list **b)
{
	if (!ft_swap(b))
		return (0);
	return (1);
}

int	ss(t_list **a, t_list **b)
{
	if (!ft_swap(a))
		return (0);
	if (!ft_swap(b))
		return (0);
	return (1);
}
