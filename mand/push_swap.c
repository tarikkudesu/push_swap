/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:46:24 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/14 14:50:11 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_doubles(int nb, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (nb == tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_set_positions(t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

void	ft_init_stack(t_list **stack_a, char **argv)
{
	int		i;
	int		j;
	char	**args;
	t_list	*new;

	i = -1;
	while (*(argv + ++i))
	{
		j = -1;
		args = ft_split(*(argv + i), ' ');
		if (!args || !*args)
			ft_exit(stack_a, NULL, args);
		while (*(args + ++j))
		{
			new = unpenetrable_parcing(*(args + j));
			if (!new || !ft_doubles(new->data, stack_a))
				ft_exit(stack_a, NULL, args);
			ft_lstadd_back(stack_a, new);
		}
		ft_free_arr(args);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (1 == argc || (2 == argc && !**(argv + 1)))
		return (1);
	stack_b = NULL;
	stack_a = NULL;
	ft_init_stack(&stack_a, argv + 1);
	sort_stack(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
}
