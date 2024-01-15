/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:12:31 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/15 15:36:41 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_min(t_list **a)
{
	t_list			*tmp;
	int				min_value;
	unsigned int	min_position;

	tmp = *a;
	if (!tmp)
		return (-1);
	min_value = tmp->data;
	min_position = tmp->position;
	while (tmp)
	{
		if (tmp->data < min_value)
		{
			min_value = tmp->data;
			min_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (min_position);
}

void	ft_sort3(t_list **a)
{
	t_list	*second;

	second = (*a)->next;
	if ((*a)->data > second->data && (*a)->data > second->next->data)
	{
		if (second->data > second->next->data)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if ((*a)->data < second->data && (*a)->data < second->next->data)
	{
		sa(a);
		ra(a);
	}
	else
	{
		if (second->data > second->next->data)
			rra(a);
		else
			sa(a);
	}
}

void	ft_sort4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	ft_set_positions(stack_a);
	min = ft_min(stack_a);
	if (3 == min)
		rra(stack_a);
	else
		while (min--)
			ra(stack_a);
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort3(stack_a);
		pa(stack_a, stack_b);
	}
}

void	ft_sort5(t_list **stack_a, t_list **stack_b)
{
	int	min;

	ft_set_positions(stack_a);
	min = ft_min(stack_a);
	if (4 == min)
		rra(stack_a);
	else
		while (min--)
			ra(stack_a);
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		ft_sort4(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	simple_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (1 >= size)
		return ;
	else if (2 == size)
		sa(stack_a);
	else if (3 == size)
		ft_sort3(stack_a);
	else if (4 == size)
		ft_sort4(stack_a, stack_b);
	else if (5 == size)
		ft_sort5(stack_a, stack_b);
}
