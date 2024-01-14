/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:42:03 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 20:33:03 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	apply(t_list **a, t_list **b, int nb)
{
	if (nb == 11)
		sa(a);
	else if (nb == 12)
		sb(b);
	else if (nb == 13)
		ss(a, b);
	else if (nb == 21)
		pa(a, b);
	else if (nb == 22)
		pb(a, b);
	else if (nb == 31)
		ra(a);
	else if (nb == 32)
		rb(b);
	else if (nb == 33)
		rr(a, b);
	else if (nb == 41)
		rra(a);
	else if (nb == 42)
		rrb(b);
	else if (nb == 43)
		rrr(a, b);
}

void	apply_insttructions(t_list **a, t_list **b, t_list **inst)
{
	t_list	*tmp;

	tmp = *inst;
	while (tmp)
	{
		apply(a, b, tmp->data);
		tmp = tmp->next;
	}
	print(inst, a);
	if (is_sorted(a) && !(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
